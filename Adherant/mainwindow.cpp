#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherant.h"
#include "QMessageBox"
#include "QIntValidator"
#include "membre.h"

#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"
#define NAME_RX "([A-Z][a-z]*)([\\s\\\'.][A-Z][a-z]*)*"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




        QRegExp rxEmail(EMAIL_RX);
        QRegExpValidator *valiEmail = new QRegExpValidator(rxEmail, this);
        ui->le_image_2->setValidator(valiEmail);

        //Controle de saisie Nom
        QRegExp rxName(NAME_RX);
        QRegExpValidator *valiName = new QRegExpValidator(rxName, this);
        ui->le_nom->setValidator(valiName);




    //controle de saisir
    ui->le_id->setValidator(new QIntValidator(100, 9999999, this));
    ui->le_tele->setValidator(new QIntValidator(100, 9999999, this));

    ui->tableView_adherant_14->setModel(A.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_adherant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_famille_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_finance_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_logistique_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_physiques_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_retour_adherant_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_adherant_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_famille_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_finance_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_logistique_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_physique_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_adherant_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_adherant_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_retour_adherant_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_ajouter_adherant_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->text();
    int tele=ui->le_tele->text().toInt();
    QString image=ui->le_image->text();
    Adherant A(id,nom,prenom,fonction,tele,image);

    bool test=A.ajouter();


        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tableView_adherant_14->setModel(A.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Warning"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        }

        ui->le_id->clear();
        ui->le_tele->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_fonction->clear();
        ui->le_image->clear();
}



void MainWindow::on_pushButton_supprimer_clicked()
{
    int id= ui->id_2->text().toInt();
    bool test=A.supprimer(id);
    if(test)
    {
        ui->tableView_2->setModel(A.afficher());

    QMessageBox::information(nullptr,QObject::tr("supprimer un Adherant"),QObject::tr("Adherant supprimé. \n ""click cancel to exit."),QMessageBox::Cancel);
    }



         ui->le_id->clear();


}



void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->le_id->text().toInt();
    int tele = ui->le_tele->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString fonction = ui->le_fonction->text();
    QString image = ui->le_image->text();
    Adherant A(id,nom,prenom,fonction,tele,image);
    bool test = A.modifier();
    if(test)
    {

      ui->tableView_adherant_14->setModel(A.afficher());
    QMessageBox::information(nullptr,QObject::tr("modifier un patient"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->le_id->clear();
    ui->le_tele->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_fonction->clear();
    ui->le_image->clear();
}



void MainWindow::on_pushButton_afficher_clicked()
{
     ui->tableView_2->setModel(A.afficher());
}

void MainWindow::on_pushButton_afficher_adherant_clicked()
{
    ui->tableView_adherant_14->setModel(A.afficher());
}

void MainWindow::on_ajouter_adherant_m_clicked()
{
    int idm=ui->le_id_2->text().toInt();
    QString nomm=ui->le_nom_2->text();
    QString prenomm=ui->le_prenom_2->text();
    QString fonctionm=ui->le_fonction_2->text();
    int telem=ui->le_tele_2->text().toInt();
    QString imagem=ui->le_image_2->text();
    Membre M(idm,nomm,prenomm,fonctionm,telem,imagem);

    bool test=M.ajouter();


        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tableView_m1->setModel(M.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Warning"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        }

        ui->le_id_2->clear();
        ui->le_tele_2->clear();
        ui->le_nom_2->clear();
        ui->le_prenom_2->clear();
        ui->le_fonction_2->clear();
        ui->le_image_2->clear();
}

void MainWindow::on_pushButton_afficher_m1_clicked()
{
    ui->tableView_m1->setModel(M.afficher());

}

void MainWindow::on_pushButton_modifier_m_clicked()
{
    int idm = ui->le_id_2->text().toInt();
    int telem = ui->le_tele_2->text().toInt();
    QString nomm=ui->le_nom_2->text();
    QString prenomm = ui->le_prenom_2->text();
    QString fonctionm = ui->le_fonction_2->text();
    QString imagem = ui->le_image_2->text();
    Membre M(idm,nomm,prenomm,fonctionm,telem,imagem);
    bool test = M.modifier();
    if(test)
    {

      ui->tableView_m1->setModel(M.afficher());
    QMessageBox::information(nullptr,QObject::tr("modifier un Adherant"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->le_id_2->clear();
    ui->le_tele_2->clear();
    ui->le_nom_2->clear();
    ui->le_prenom_2->clear();
    ui->le_fonction_2->clear();
    ui->le_image_2->clear();
}


void MainWindow::on_pushButton_supprimer_m_clicked()
{
    int idm= ui->id_3->text().toInt();
    bool test=M.supprimer(idm);
    if(test)
    {
        ui->tableView_m2->setModel(M.afficher());

    QMessageBox::information(nullptr,QObject::tr("supprimer un Membre"),QObject::tr("Membre supprimé. \n ""click cancel to exit."),QMessageBox::Cancel);
    }



         ui->id_3->clear();

}

void MainWindow::on_pushButton_afficher_m2_clicked()
{
    ui->tableView_m2->setModel(M.afficher());

}