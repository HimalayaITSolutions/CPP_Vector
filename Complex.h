#pragma once

    class Complex
    {
    public:
        Complex() = delete;  // see if this has an impact
        Complex(double r, double i);
        Complex(double r);
        virtual ~Complex();

        // Getter/Setters
        // inline for perf
        double getReal() const { return re; }
        double getImg() const { return img; }
        void setReal(double r) { re = r; } // Scope for Error\Exception
        void setImg(double i) { img = i; }

        // Basic Arithmetic
        // Choose input carefully, no mutate but affect internal state
        Complex& operator+=(Complex& b);
        Complex& operator-=(Complex& b);
        Complex& operator*=(Complex& b);

        //Basic Comparison
        // Easy as no mutation, cant define it as const yet
        bool operator==(Complex& b);
       


    private:
        double re, img;
    };

    // This can modify internal state so copy by value. Use Internal function to return objects.
    // Base them on Class functions and can use them as generic objects.
    Complex operator+(Complex a, Complex b);
    Complex operator-(Complex a, Complex b);
    Complex operator*(Complex a, Complex b);
    bool operator!=(Complex &a, Complex& b);