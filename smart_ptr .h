#pragma once

template<typename T>
class smart_ptr {
private:
    T* ptr;

public:
    // �����������
    explicit smart_ptr(T* p = nullptr) : ptr(p) {}

    // ����������
    ~smart_ptr() {
        delete ptr;
    }

    // ������ �����������
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator=(const smart_ptr&) = delete;

    // ���������� �����������
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

    // ������ � �������
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // �������� ���������� ���������
    T* get() const { return ptr; }

    // ���������� ������ �������
    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }

    // ���������� �������� (��� ��������)
    T* release() {
        T* oldPtr = ptr;
        ptr = nullptr;
        return oldPtr;
    }
};