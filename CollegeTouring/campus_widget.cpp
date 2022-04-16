#include "campus_widget.h"
#include "campus.h"

//Note that the constructor initializes a campus associated with the object so that we know which campus the user is messing with.
CampusWidget::CampusWidget(Campus campusPassed, MainWindow *parent)
    :campus{campusPassed}, parent{parent}
{

    //Creating all the UI elements dynamically for each campus column in the list widget.
    layout = new QHBoxLayout(this);
    nameLabel = new QLabel(campus.getStartCollege());
    addButton = new QPushButton("Add Campus");
    menuItems = new QComboBox();
    itemsToAdd = new QSpinBox();
    itemsToAdd->setFixedSize(100, 20);
    itemsToAdd->setMaximum(100);
    addItemButton = new QPushButton("Add menu item(s)");

    //Iterating over the menu to add items to the menu ComboBox
    for (int i = 0; i < this->campus.getMenu().size(); i++)
    {
        menuItems->addItem(QString(this->campus.getMenu()[i].name + ": " + QString::number(this->campus.getMenu()[i].price)));
    }

    //Run on_AddMenuItemClicked() method in this class when "Add Items" button has been clicked
    addItemButton->connect(addItemButton, SIGNAL(clicked()), this, SLOT(on_AddMenuItemClicked()));
    //Run on_AddCampusClicked() method in this class when "Add Campus" button has been clicked
    addButton->connect(addButton, SIGNAL(clicked()), this, SLOT(on_AddCampusClicked()));

    //Adding all input widgets to our QHBoxLayout that groups them all together.
    layout->addWidget(nameLabel);
    layout->addWidget(addButton);
    layout->addWidget(menuItems);
    layout->addWidget(itemsToAdd);
    layout->addWidget(addItemButton);
}

void CampusWidget::on_AddCampusClicked() {
    QString name = this->campus.getStartCollege();
    qInfo() << "Campus clicked: " << name;

    //adding campus to FoodApp selectedCampuss vector (to keep track of which campuss they want in the trip)
    parent->addCampus(this->campus);

    //adding campus to GUI list
    parent->addToList(name);


}

void CampusWidget::on_AddMenuItemClicked(){
    //Gather UI data
    //Gets how many items they want to buy
    int count = this->itemsToAdd->value();
    //Index of menu ComboBox - necessary to know since we need to know which item they want.
    int currentIndex = this->menuItems->currentIndex();
    //Name of the item they're buying
    QString itemName = this->campus.getMenu()[currentIndex].name + " - $" + QString::number(this->campus.getMenu()[currentIndex].price);

    //Code below is for validating they're not adding more than 100 of the same item
    int itemCount = 0;
    std::vector<QString> itemsAdded = parent->getMenuList();

    //Loop through existing menu items added to see how many we've already added for this specific kind of item
    //Need to do this since we can only add 100 of the same item in a trip
    for (int i = 0; i < itemsAdded.size(); i++){
        if (itemsAdded[i] == itemName){
            itemCount++;
        }
    }

    //actual foodapp connection
    if (itemCount + count <= 100){
        //Loop count times where count is the number of items being added
        for (int i = 0; i < count; i++){
            //Add menu item to CampusApp selectedItems to keep track of which items have been bought for each campus
            parent->addMenuItem(this->campus, this->campus.getMenu()[currentIndex]);
            //Add menu item to GUI/UI list
            parent->addToMenuList(itemName, this->campus.getStartCollege());
        }
    } else {
        qInfo() << "Error! Cannot add more than 100 of the same item.";
        QMessageBox popup;
        popup.critical(0, "Error", "Cannot add more than 100 of the same item at a time.");
    }
}

CampusWidget::~CampusWidget(){
    delete layout;
    delete nameLabel;
    delete addButton;
    delete menuItems;
}
