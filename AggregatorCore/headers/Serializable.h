#ifndef Serializable_H
#define Serializable_H

#pragma once


template <typename T>
class Serializable
{
public:
    
    virtual QJsonObject toJson() const = 0;
    virtual T fromJson(const QJsonObject &&json) = 0;
    virtual ~Serializable() { };

};

#endif // Serializable_H
