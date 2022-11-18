/// @file fenetre.h
/// @version 5.15.2 qt
/// @author M.Bulcke
#include "pixelix.h"

pixelix::pixelix()
{

}
/**
 * @brief Creation du json text pour Pixelit
 * @param text qui envoie le texte à l'afficheur de type  QString
 * @param color qui envoie la couleur du texte de type QColor
 * @param scroll
 */
void pixelix::text(QString text, QColor color, bool scroll)
{

    // Creation de json text pour Pixelit
    QJsonObject jtext;
    QJsonObject jcolor;
    QJsonObject jposition;

    jtext["textString"] = text;
    jtext["bigFont"] = false;
    jtext["scrollText"] = scroll;
    jtext["scrollTextDelay"] = 100;
    jtext["centerText"] = false;
    jposition["x"] = 8;
    jposition["y"] = 0;
    jtext["position"] = jposition;
    jtext["hexColor"] = color.name();
    jsontext["text"] = jtext;

}
/**
 * @brief pixelix::set_brightness
 * @param lum
 * @return true, false
 */
bool pixelix::set_brightness(int lum)
{
    qDebug() << lum;

    jsonbrightness["brightness"] = lum;

    QUrl url = qurl;
    url.setPath("/api/screen");

    qDebug() << jsonbrightness << url;

    QByteArray p = post(url, jsontext);

    QString good_response = "OK";
    if (p.contains(good_response.toUtf8())){
        return true;
    }
    else {
        return false;
    }

}
/**
 * @brief pixelix::set_url
 * @param url
 */
void pixelix::set_url(QString url)
{
    qurl = QUrl(url);
}

bool pixelix::envoyer_txt()
{
    QUrl url = qurl;
    url.setPath("/api/screen");
    QByteArray p = post(url, jsontext);

    QString good_response = "OK";
    if (p.contains(good_response.toUtf8())){
        return true;
    }
    else {
        return false;
    }

}
/**
 * @brief pixelix::get_brightness
 * @return
 */
double pixelix::get_brightness()
{
    QUrl url = qurl;
    url.setPath("/api/brightness");

    //la reponse de l'api est stockée dans un json
    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    //on transforme le json en objet json
    QJsonObject objetJSON = documentJSON.object();

    //on cherche la clé "brightness" et on vérifie que la valeur est un double
    if(objetJSON.value("brightness").isDouble())
    {
        return objetJSON.value("brightness").toDouble();
    }
    else
    {
        return 0;
    }
}
/**
 * @brief pixelix::get
 * @param url
 * @return
 */
QByteArray pixelix::get(QUrl url)
{

    QNetworkRequest requete(url);

//    //Pour la gestion de la connexion sécurisée SSL (HTTPS)
//    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
//    config.setProtocol(QSsl::TlsV1_2);
//    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;

}

/**
 * @brief pixelix::post
 * @param url
 * @param json
 * @return
 */
QByteArray pixelix::post(QUrl url, QJsonObject json)
{
    QNetworkRequest requete(url);
    requete.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m.post(requete, QJsonDocument(json).toJson());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();
    return read;
}

/**
 * @brief pixelix::get_json_brightness
 * @return
 */
QByteArray pixelix::get_json_brightness()
{
    QUrl url = qurl;
    url.setPath("/api/brightness");
    return get(url);

}
