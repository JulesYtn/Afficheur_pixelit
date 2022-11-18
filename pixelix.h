/// @file fenetre.h
/// @version 5.15.2 qt
/// @author M.Bulcke
#ifndef PIXELIX_H
#define PIXELIX_H

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>

/**
 * @brief la classe pixelit nous sers à envoyer du texte et gérer la lumiere de l'afficheur
 */
class pixelix
{

private:
    /**
     * @brief qurl
     */
    QUrl qurl;
    /**
     * @brief jsontext va nous permettre d'envoyer du texte à l'afficheur
     */
    QJsonObject jsontext;
    /**
     * @brief jsonbrightness va nous permettre de changer l'intensité de la lumiere de l'afficheur
     */
    QJsonObject jsonbrightness;
    /**
     * @brief get va nous permettre de vérifier l'ip de l'afficheur
     * @param url est l'ip de l'afficheur
     */
    QByteArray get(QUrl url);
    /**
     * @brief post va nous permettre de pouvoir transmettre les information
     * @param url est l'ip de l'afficheur
     * @param json est le texte et l'intensité de la lumiere a envoyer à l'afficheur
     */
    QByteArray post(QUrl url, QJsonObject json);
    /**
     * @brief m
     */
    QNetworkAccessManager m;


public:
    /**
     * @brief pixelix constructeur de la classe
     */
    pixelix();
    /**
     * @brief text permet de creer un json pour pixelit
     * @param text le texte qu'on veux envoyer à l'afficheur
     * @param color la couleur du texte qu'on veux mettre sur l'afficheur
     * @param scroll si l'on veux faire défilé le texte sur l'afficheur
     */
    void text(QString text, QColor color, bool scroll);
    /**
     * @brief set_url nous permet décrire l'ip de l'afficheur
     * @param url est l'ip de l'afficheur
     */
    void set_url(QString url);
    /**
     * @brief set_brightness nous permet de changer la luminosité du texte sur l'afficheur
     * @param lum est l'intensité de la lumiere
     * @return true ou false
     */
    bool set_brightness(int lum);
    /**
     * @brief envoyer_txt nous permet d'envoyer le texte sur l'afficheur
     * @return true ou false
     */
    bool envoyer_txt();
    /**
     * @brief get_json_brightness nous permet de recuperer l'intensite de la lumiere sur l'afficheur en json
     * @return true ou false
     */
    QByteArray get_json_brightness();
    /**
     * @brief get_brightness nous permet de traduire le json en json objet
     */
    double get_brightness();


};

#endif // PIXELIX_H
