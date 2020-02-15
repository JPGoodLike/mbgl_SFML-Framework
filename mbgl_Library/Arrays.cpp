#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>

template <typename T>
class SArray {
    private:
        int len;
        T* items;

    public:
        SArray(int len = 0) {
            this->len = len;
            items = new T[len];
        }
        ~SArray() {
            Clean();
        }
        
        void Set(const SArray<T>& other) {
            if (len != other.Length()) {
                Clean();
                len = other.Length();
                items = new T[len];
            }
            for (int i = 0; i < len; i++) {
                items[i] = other[i];
            }
        }

        int Length() const {
            return len;
        }

        void Clean() {
            delete[] items;
            len = 0;
        }
        
        void operator=(const SArray<T>& other) {
            Set(other);
        }
        
        T& operator[](int i) const {
            if (0 <= i && i < len) {    
                return items[i];
            } else
                throw std::invalid_argument("Index is out of the array range");
        }

        friend std::ostream& operator<<(std::ostream& stream, const SArray& array) {
            for (int i = 0; i < array.Length() - 1; i++) {
                stream << array[i] << " ";
            }
            stream << array[array.Length()-1];
            return stream;
        }
};

template <typename T>
class DArray {
    private:
        int capacity;

        int len;
        T* items;

    public:
        DArray(int len = 0) 
        : capacity(len), len(len) { 
            if (capacity > 0) {           
                items = new T[len];
            } else
                items = nullptr;
        }
        DArray(const DArray<T>& other)
        : capacity(0), len(0), items(nullptr) {
            Set(other);
        }
        ~DArray() {
            Clean();
        }
        
        void SetCapacity(int new_capacity) {
            if (new_capacity == 0)
                return;

            capacity = new_capacity;
            T* new_items = new T[capacity];
            int bound = std::min(len, capacity);
            for (int i = 0; i < bound; i++) {
                new_items[i] = items[i];
            }
            delete[] items;
            items = new_items;
        }
        void Set(const DArray<T>& other) {
            if (other.Length() > capacity) {
                Clean();             
                capacity = other.Length();
                items = new T[capacity];
            }

            len = other.Length();
            for (int i = 0; i < len; i++) {
                items[i] = other[i];
            }
        }

        int Length() const {
            return len;
        }
        int Size() const {
            return len;
        }

        void Clean() {
            if (capacity > 0) {
                delete[] items;
                items = nullptr;
                capacity = 0;
                len = 0;
            }
        }

        DArray<T> SubArray(int startI, int lastI) const {
            int subALen = lastI - startI + 1;
            DArray<T> subA(subALen);
            for(int i = 0, j = startI; i < subA.len; i++, j++)
                subA[i] = items[j];
            return subA;
        }

        //dynamic array methods


        void Push(T item) {
            if (len + 1 > capacity) {
                int new_capacity = (capacity == 0 ? 1 : capacity * 2);
                SetCapacity(new_capacity);
            }
            items[len] = item;
            len++;
        }

        T Pop() {
            if (len <= 0)
                throw std::invalid_argument("Attempt to pop a non-existing item");

            len--;
            return items[len];
        }

        void Insert(T item, int index) {
            if (index < 0 || index > len)
                throw std::invalid_argument("Index is out of the array range");

            if (len + 1 > capacity) {
                int new_capacity = (capacity == 0 ? 1 : capacity * 2);
                SetCapacity(new_capacity);
            }
            for (int i = len; i > index; i--) {
                items[i] = items[i-1];
            }
            items[index] = item;
            len++;
        }

        void Extend(unsigned int value) {
            if (len + value > capacity) {
                int upB = std::max(len + (long)value, (long)capacity);
                int new_capacity = (capacity == 0 ? 1 : upB * 2);
                SetCapacity(new_capacity);
            }
            int newLen = len + value;
            for (int i = len; i < newLen; i++)
                items[i] = 0;

            len = newLen;

        }

        void ShrinkTop(unsigned int value) {
            if (value > len)
                std::invalid_argument("Shrinking value is greater than the array length");
            
            len -= value;
        }
        
        T& operator[](int i) const {
            if (i < 0 || i >= len)
                throw std::invalid_argument("Index is out of the array range");

            return items[i];
        }

        DArray& operator=(const DArray& other) {
            Set(other);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& stream, const DArray& array) {
            if (array.Length() > 0) {
                for (int i = 0; i < array.Length() - 1; i++) {
                    stream << array[i] << " ";
                }
                stream << array[array.Length()-1];
            }
            return stream;
        }
};