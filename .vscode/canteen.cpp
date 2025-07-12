#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Order {
    string customerName;
    string foodItem;
    int price;
    int timeToServe; // time in minutes for each item
};

class CanteenQueue {
    queue<Order> orders;
public:
    void enqueue(string name, string food, int price) {
        Order newOrder;
        newOrder.customerName = name;
        newOrder.foodItem = food;
        newOrder.price = price;
        newOrder.timeToServe = 2;  // Each order takes 2 minutes

        orders.push(newOrder);
        cout << "Order placed successfully!\n";
    }

    void serveOrder() {
        if (orders.empty()) {
            cout << "No pending orders to serve.\n";
            return;
        }

        Order servedOrder = orders.front();
        orders.pop();

        cout << "Serving Order: " << servedOrder.customerName
             << " - " << servedOrder.foodItem << "\n";
        cout << "Your total is: " << servedOrder.price << " Rs.\n";
        cout << "Your order was served in " << servedOrder.timeToServe << " minute(s).\n";
        cout << "Thank you! Visit again.\n";
    }

    void displayQueue() {
        if (orders.empty()) {
            cout << "No pending orders.\n";
            return;
        }

        int currentTime = 0;
        cout << "Pending Orders:\n";
        queue<Order> tempQueue = orders; // Copy the queue to traverse it

        while (!tempQueue.empty()) {
            Order order = tempQueue.front();
            tempQueue.pop();

            currentTime += order.timeToServe;
            cout << order.customerName << " - " << order.foodItem
                 << " (Estimated time to serve: " << currentTime << " min)\n";
        }
    }
};

void showMenu() {
    cout << "\n===== Welcome to the Canteen! =====\n";
    cout << "==============================\n";
    cout << "Menu:\n";
    cout << "1. Poha [20 Rs]\n";
    cout << "2. Upma [20 Rs]\n";
    cout << "3. Chai [10 Rs]\n";
    cout << "4. Samosa [20 Rs]\n";
    cout << "5. Sandwich [20 Rs]\n";
    cout << "6. Vada Pav [20 Rs]\n";
    cout << "7. Bread with Butter [15 Rs]\n";
    cout << "8. Patties [20 Rs]\n";
    cout << "9. Coffee [20 Rs]\n";
    cout << "10. Biscuits [10 Rs]\n";
    cout << "==============================\n";
}

int main() {
    CanteenQueue canteen;
    int choice;
    string customerName, foodItem;
    char moreOrder;
    int totalAmount = 0;

    do {
        showMenu();

        cout << "\nEnter your name: ";
        getline(cin, customerName);

        do {
            cout << "Enter your order (food item): ";
            getline(cin, foodItem);

            // Based on food item, set the price
            int price = 0;
            if (foodItem == "Poha") price = 20;
            else if (foodItem == "Upma") price = 20;
            else if (foodItem == "Chai") price = 10;
            else if (foodItem == "Samosa") price = 20;
            else if (foodItem == "Sandwich") price = 20;
            else if (foodItem == "Vada Pav") price = 20;
            else if (foodItem == "Bread with Butter") price = 15;
            else if (foodItem == "Patties") price = 20;
            else if (foodItem == "Coffee") price = 20;
            else if (foodItem == "Biscuits") price = 10;
            else {
                cout << "Invalid food item. Please try again.\n";
                continue;  // skip rest of loop and re-ask for valid item
            }

            canteen.enqueue(customerName, foodItem, price);
            totalAmount += price;

            cout << "Would you like to order something else? (y/n): ";
            cin >> moreOrder;
            cin.ignore();  // To discard the leftover newline character
        } while (moreOrder == 'y' || moreOrder == 'Y');

        cout << "\n===== Options =====\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. View Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To discard the newline character

        switch (choice) {
            case 1:
                break; // Orders are already taken in the previous loop

            case 2:
                canteen.serveOrder();
                break;

            case 3:
                canteen.displayQueue();
                break;

            case 4:
                cout << "Exiting... Thank you for visiting! See you soon!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
