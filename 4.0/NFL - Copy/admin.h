#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();
    void  populate_team_table();
    void  populate_team_name_box();
    void reload();
    void populate_souvenir_team_name_boxe();
    void populate_souvenir_table_box();
    void souvenirload ();

private slots:




    void on_Team_Name_Combo_Box_currentTextChanged(const QString &arg1);

    void on_Delete_Button_clicked();

    void on_Add_Button_clicked();

    void on_Edit_Button_clicked();

    void on_souvenir_name_combo_box_currentTextChanged(const QString &arg1);

    void on_souvenir_name_combo_box_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Team_name_souvenir_box_currentIndexChanged(const QString &arg1);

    void on_Remove_expansion_button_clicked();

    void on_Add_expansion_button_clicked();

private:
    Ui::admin *ui;

};

#endif // ADMIN_H
