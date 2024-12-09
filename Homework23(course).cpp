/*1)
#include <iostream>
#include <stdexcept>  
int main() {
    try {
        
        throw std::runtime_error("An error has occurred!");  
    }
    catch (const std::runtime_error& e) { 
        
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}*/
/*2)
#include <iostream>
#include <stdexcept>
#include <string>

class MyException : public std::runtime_error {
public:
    
    MyException(const std::string& message, int errorCode)
        : std::runtime_error(message), errorCode(errorCode) {}

    int getErrorCode() const {
        return errorCode;
    }

private:
    int errorCode;  
};

int main() {
    try {
        
        throw MyException("An error has occurred!", 101);  
    }
    catch (const MyException& e) {  
        
        std::cout << "Caught an exception: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;  
    }

    return 0;
}
*/
/*3)
#include <iostream>
#include <stdexcept>
#include <string>

class MyException : public std::runtime_error {
public:
    MyException(const std::string& message, int errorCode)
        : std::runtime_error(message), errorCode(errorCode) {}

    int getErrorCode() const {
        return errorCode;
    }

private:
    int errorCode;
};

class DerivedException : public MyException {
public:
    DerivedException(const std::string& message, int errorCode, const std::string& details)
        : MyException(message, errorCode), details(details) {}

    const std::string& getDetails() const {
        return details;
    }

private:
    std::string details;
};

int main() {
    try {
        throw DerivedException("Derived error occurred!", 102, "Additional details about the error");
    } catch (const DerivedException& e) {  
        std::cout << "Caught a derived exception: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
        std::cout << "Details: " << e.getDetails() << std::endl;
    } catch (const MyException& e) {  
        std::cout << "Caught a base exception: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
    }

    return 0;
}
*/
/*4)
#include <iostream>
#include <stdexcept>
#include <string>


class MyException : public std::runtime_error {
public:
    MyException(const std::string& message, int errorCode)
        : std::runtime_error(message), errorCode(errorCode) {}

    int getErrorCode() const {
        return errorCode;
    }

private:
    int errorCode;
};

class DerivedException : public MyException {
public:
    DerivedException(const std::string& message, int errorCode, const std::string& details)
        : MyException(message, errorCode), details(details) {}

    const std::string& getDetails() const {
        return details;
    }

private:
    std::string details;
};

void functionLevelThree() {
    
    throw DerivedException("Derived error occurred at level 3!", 103, "Additional details from level 3");
}

void functionLevelTwo() {
    functionLevelThree();
}

void functionLevelOne() {
    functionLevelTwo();
}

int main() {
    try {
        functionLevelOne();
    } catch (const DerivedException& e) {  
        std::cout << "Caught a derived exception: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
        std::cout << "Details: " << e.getDetails() << std::endl;
    } catch (const MyException& e) {  
        std::cout << "Caught a base exception: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
    }

    return 0;
}
*/