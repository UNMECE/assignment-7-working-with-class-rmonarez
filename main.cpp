nclude <iostream>
#include <cmath>

class Electric_Field {
private:
    double *E;

public:
    // Default constructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0}; // Initialize with zero values
    }

    // Parameterized constructor
    Electric_Field(double Ex, double Ey, double Ez) {
        E = new double[3]{Ex, Ey, Ez}; // Initialize with provided values
    }

    // Destructor
    ~Electric_Field() {
        delete[] E;
    }

    // Setters
    void setField(double Ex, double Ey, double Ez) {
        E[0] = Ex;
        E[1] = Ey;
        E[2] = Ez;
    }

    // Getters
    double getEx() const { return E[0]; }
    double getEy() const { return E[1]; }
    double getEz() const { return E[2]; }

    // Calculate magnitude
    double calculateMagnitude() const {
        return std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    // Calculate inner product (dot product)
    double innerProduct() const {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }

    // Output inner product
    void printInnerProduct() const {
        std::cout << "Electric Field Inner Product: " << innerProduct() << std::endl;
    }
};

class Magnetic_Field {
private:
    double *B;

public:
    // Default constructor
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0}; // Initialize with zero values
    }

    // Parameterized constructor
    Magnetic_Field(double Bx, double By, double Bz) {
        B = new double[3]{Bx, By, Bz}; // Initialize with provided values
    }

    // Destructor
    ~Magnetic_Field() {
        delete[] B;
    }

    // Setters
    void setField(double Bx, double By, double Bz) {
        B[0] = Bx;
        B[1] = By;
        B[2] = Bz;
    }

    // Getters
    double getBx() const { return B[0]; }
    double getBy() const { return B[1]; }
    double getBz() const { return B[2]; }

    // Calculate magnitude
    double calculateMagnitude() const {
        return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    // Calculate unit vector
    void unitVector() const {
        double magnitude = calculateMagnitude();
        if (magnitude == 0) {
            std::cout << "Cannot calculate unit vector for zero vector." << std::endl;
            return;
        }
        std::cout << "Magnetic Field Unit Vector: (" 
                  << B[0] / magnitude << ", " 
                  << B[1] / magnitude << ", " 
                  << B[2] / magnitude << ")" << std::endl;
    }
};

int main() {
    // Create Electric and Magnetic fields using both constructors
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Magnetic_Field B_default;
    Magnetic_Field B_components(3.0, 4.0, 0.0);

    // Set values for fields using setters
    E_default.setField(1.0, 2.0, 3.0);
    B_default.setField(0.0, 1.0, 0.0);

    // Output magnitudes
    std::cout << "Electric Field Magnitude (default): " << E_default.calculateMagnitude() << std::endl;
    std::cout << "Electric Field Magnitude (components): " << E_components.calculateMagnitude() << std::endl;

    std::cout << "Magnetic Field Magnitude (default): " << B_default.calculateMagnitude() << std::endl;
    std::cout << "Magnetic Field Magnitude (components): " << B_components.calculateMagnitude() << std::endl;

    // Output inner product for Electric Field
    E_default.printInnerProduct();
    E_components.printInnerProduct();

    // Output unit vector for Magnetic Field
    B_default.unitVector();
    B_components.unitVector();

    return 0;
}

