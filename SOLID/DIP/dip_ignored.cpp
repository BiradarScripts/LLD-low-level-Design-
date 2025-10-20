#include <iostream>
#include <string>

class ConsoleLogger {
public:
    void log(const std::string& msg) { std::cout << "[LOG] " << msg << "\n"; }
};

class StripeGateway {
public:
    bool pay(int cents) {
        std::cout << "Stripe: charged " << cents << " cents\n";
        return true;
    }
};

// High-level module directly constructs low-level details (bad)
class BillingService {
public:
    void charge(int cents) {
        ConsoleLogger logger;          // concrete dependency
        StripeGateway gateway;         // concrete dependency
        logger.log("Charging customer...");
        if (gateway.pay(cents)) logger.log("Payment succeeded");
    }
};

int main() {
    BillingService svc;
    svc.charge(5000);
}



// When DIP is ignored
// Your main class (BillingService) creates a ConsoleLogger and a StripeGateway inside itself.
// That means it is hard-wired to those exact classes.
// If you want PayPal tomorrow or a file logger, you must edit BillingService and recompile.
// Testing is painful—you can’t swap in a fake gateway/logger without changing the class.
// Think: a TV with the HDMI cable soldered in. Want another device? You have to open the TV