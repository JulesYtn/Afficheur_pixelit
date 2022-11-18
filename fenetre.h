/// @file fenetre.h
/// @version 5.15.2 qt
/// @author M.Bulcke
#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>

#include "pixelix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fenetre; } /// @namespace Ui pour la classse fenetre
QT_END_NAMESPACE

/**
 * @brief La classse de la fenetre qui va s'afficher en lancant le programme
 */
class fenetre : public QMainWindow
{
    Q_OBJECT
    /**
 * @brief fenetre
 * @param parent
 */
public:
    /**
     * @brief fenetre est le constructeur
     * @param parent
     */
    fenetre(QWidget *parent = nullptr);
    ~fenetre();
    /**
     * @brief couleur  va nnous permettre de changer la couleur du texte à l'afficheur
     */
    QColor couleur = Qt::white;

private slots:
    /**
     * @brief telecharger_brightness va nous permettre de récupérer l'intensité de la lumiere emise sur l'afficheur
     */
    void telecharger_brightness();
    /**
     * @brief envoyer_txt va nousp permettre d'envoyer du texte sur l'afficheur
     */
    void envoyer_txt();
    /**
     * @brief choixcouleur va nous permettre d'avoir un choix de couleur pour le texte a envoyer sur l'afficheur
     */
    void choixcouleur();
    /**
     * @brief changer_url va nous permettre de changer l'adresse ip
     */
    void changer_url();
    /**
     * @brief change_brightness va nous permettre de changer l'intensité de la lumiere du texte afficher sur l'afficheur
     */
    void change_brightness();

//    void reponse_terminee(QNetworkReply *reply);

private:
    /**
     * @brief ui
     */
    Ui::fenetre *ui;
    /**
     * @brief erreurTrouvee va nous permettre de ne pas lancer le programme si nous avons une erreur
     */
    bool erreurTrouvee = false;
    /**
     * @brief afficheur
     */
    pixelix afficheur;
//    QByteArray answer;
//    QNetworkAccessManager *m;
//    QNetworkRequest requete;
//    bool getfini = false;


};
#endif // FENETRE_H
