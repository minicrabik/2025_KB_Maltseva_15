#pragma once

template<typename T>
class smart_ptr {
private:
    T* ptr;

public:
    // Конструктор
    explicit smart_ptr(T* p = nullptr) : ptr(p) {}

    // Деструктор
    ~smart_ptr() {
        delete ptr;
    }

    // Запрет копирования
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator=(const smart_ptr&) = delete;

    // Разрешение перемещения
    smart_ptr(smart_ptr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    smart_ptr& operator=(smart_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Доступ к объекту
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // Получить внутренний указатель
    T* get() const { return ptr; }

    // Освободить объект вручную
    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }

    // Освободить владение (без удаления)
    T* release() {
        T* oldPtr = ptr;
        ptr = nullptr;
        return oldPtr;
    }
};