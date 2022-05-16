#include "menuwidget.h"

MenuWidget::MenuWidget(Campus campus, MainWindow *parent)
    : campus{campus}, parent{parent}
{

    //Creating all the UI elements dynamically for each restaurant column in the list widget.
    layout = new QHBoxLayout(this);
    stateLabel = new QLabel(campus.getState());
    stateLabel->setFixedWidth(90);
    nameLabel = new QLabel(campus.getStartCollege());
    nameLabel->setFixedWidth(280);
    addNewItemButton = new QPushButton("Add Item");
    addNewItemButton->setFixedSize(150, 30);
    menuItems = new QComboBox();
    deleteItemButton = new QPushButton("Delete item");
    deleteItemButton->setFixedSize(150, 30);
    editItemButton = new QPushButton("Edit item");
    editItemButton->setFixedSize(150, 30);

    //Iterating over the menu to add items to the menu ComboBox
    for (int i = 0; i < this->campus.getMenu().size(); i++)
    {
        menuItems->addItem(QString(this->campus.getMenu()[i].name + ": $" + QString::number(this->campus.getMenu()[i].price)));
    }

    //Run on_AddMenuItemClicked() method in this class when "Add Items" button has been clicked
    addNewItemButton->connect(addNewItemButton, SIGNAL(clicked()), this, SLOT(on_AddMenuItemClicked()));
    //Run on_AddRestaurantClicked() method in this class when "Add Restaurant" button has been clicked
    deleteItemButton->connect(deleteItemButton, SIGNAL(clicked()), this, SLOT(on_DeleteMenuItemClicked()));

    editItemButton->connect(editItemButton, SIGNAL(clicked()), this, SLOT(on_EditMenuItemClicked()));

    //Adding all input widgets to our QHBoxLayout that groups them all together.
    layout->addWidget(stateLabel);
    layout->addWidget(nameLabel);
    layout->addWidget(menuItems);
    layout->addWidget(addNewItemButton);
    layout->addWidget(deleteItemButton);
    layout->addWidget(editItemButton);
}

/* FUNCTIONS CALLED ON BUTTON CLICK */

void MenuWidget::on_AddMenuItemClicked(){
    qInfo() << "Add item clicked.";

    if (this->campus.getMenu().size() >= 8){
        QMessageBox popup;
        popup.critical(0, "Error", "Maximum of 8 items per college.");
    } else {
        this->parent->addItem(this->campus, this->campus.getMenu());
    }
}

void MenuWidget::on_DeleteMenuItemClicked(){
    qInfo() << "Delete item clicked.";

    //Index of menu ComboBox - necessary to know since we need to know which item they want.
    int index = this->menuItems->currentIndex();

    std::vector<Souvenir>updatedMenu = this->campus.getMenu();

    if (updatedMenu.size() > 0){
        updatedMenu.erase(updatedMenu.begin() + index);

        this->parent->deleteItem(this->campus, updatedMenu);
    } else {
        QMessageBox popup;
        popup.critical(0, "Error", "Souvenir is already empty.");
    }
}

void MenuWidget::on_EditMenuItemClicked(){
    qInfo() << "Edit item clicked.";

    int index = this->menuItems->currentIndex();
    if (index > -1)
    {
    Souvenir selected = this->campus.getMenu()[index];

    this->parent->editItem(this->campus, index);

    qInfo() << "Editing " << selected.name;
    }
    else
    {
        QMessageBox popup;
        popup.critical(0, "Error", "Souvenir is empty!");
    }
}
