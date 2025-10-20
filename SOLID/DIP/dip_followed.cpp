#include <iostream>
#include <string>
#include <memory>

// Abstractions (interfaces via abstract base classes)
class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& msg) = 0;
};

class PaymentGateway {
public:
    virtual ~PaymentGateway() = default;
    virtual bool pay(int cents) = 0;
};

// Concrete implementations depend on abstractions (details -> abstractions)
class ConsoleLogger : public Logger {
public:
    void log(const std::string& msg) override { std::cout << "[LOG] " << msg << "\n"; }
};

class StripeGateway : public PaymentGateway {
public:
    bool pay(int cents) override {
        std::cout << "Stripe: charged " << cents << " cents\n";
        return true;
    }
};

class PayPalGateway : public PaymentGateway {
public:
    bool pay(int cents) override {
        std::cout << "PayPal: charged " << cents << " cents\n";
        return true;
    }
};

// High-level module depends only on abstractions; uses DI (constructor injection)
class BillingService {
    private:
    PaymentGateway& gateway;
    Logger& logger;
public:
    BillingService(PaymentGateway& gw, Logger& lg) : gateway(gw), logger(lg) {}
    void charge(int cents) {
        logger.log("Charging customer...");
        if (gateway.pay(cents)) logger.log("Payment succeeded");
    }

};

int main() {
    ConsoleLogger logger;

    StripeGateway stripe;
    BillingService svc1(stripe, logger);
    svc1.charge(5000);

    PayPalGateway paypal;              // swap detail without touching BillingService
    BillingService svc2(paypal, logger);
    svc2.charge(7000);
}


// When DIP is followed
// You first define abstractions: Logger and PaymentGateway (just the shape of what you need).
// BillingService depends only on those abstractions and gets concrete objects injected (passed in) via its constructor.
// Concrete classes (ConsoleLogger, StripeGateway, PayPalGateway) implement the abstractions.
// To switch from Stripe to PayPal, you only change what you pass in—BillingService code stays untouched.
// Testing becomes easy: pass in a fake PaymentGateway/Logger to simulate success/failure.
// Think: a TV with ports. You can plug in any device that fits the port, no TV surgery needed