#pragma once

#ifndef DataHandler_H
#define DataHandler_H

template <typename T>
class DataHandler
{
private:

    T* impl()
    {
        return static_cast<T*>(this);
    }

public:

    T m_data = T();

    T getData() const
    {
        return m_data;
    }

    bool setData(const T &data)
    {
        m_data = data;
    }

    bool setData(T &&data)
    {
        m_data(std::move(data));
    }

    virtual ~DataHandler() { }
};

#endif // DataHandler_H
