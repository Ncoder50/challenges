class bigInt {
    public:
        bigInt();
        void set_value(int value);
        void factorial();
        void print();
        void free_class();
        void clean();

    private:
        void trail();
        void multiply(int other);
        int* values;
        int start_value;
        int len;
        int zeros;
};