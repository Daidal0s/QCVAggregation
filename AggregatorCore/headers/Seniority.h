#pragma once
#include "stdafx.h"

#include "Serializable.h"
#include "DataHandler.h"





// Seniority Data





class SeniorityData : public Serializable<SeniorityData> 
{
private:

    QDate m_firstDate = QDate(QDate::currentDate());
    QDate m_lastDate = QDate(QDate::currentDate());

public:

    SeniorityData();
    SeniorityData(const QDate &first, const QDate &last);
    SeniorityData(QDate &&first, QDate &&last);
    ~SeniorityData();

public:

    friend bool operator==(const SeniorityData &d1, const SeniorityData &d2);
    friend bool operator!=(const SeniorityData &d1, const SeniorityData &d2);

public:

    // Serialize Methods
    QJsonObject toJson() const override;
    SeniorityData fromJson(const QJsonObject &&json) override;

    QPair<QDate, QDate> getDatesPair() const;

};





// Seniority Data Handler





class Seniority : DataHandler<SeniorityData>
{
    friend DataHandler<SeniorityData>;
private:

    SeniorityData m_seniorityData;
    QDate m_seniority;
    quint64 m_seniorityInDays;

private:

    bool m_calculateSeniority();

public:

    Seniority(const QDate &firstDate, const QDate &lastDate);
    Seniority(QDate &&firstDate, QDate &&lastDate);
    ~Seniority();

public:

    // Data Handler Methods
    SeniorityData getData() const;
    bool setData(const SeniorityData &data);
    bool setData(SeniorityData &&data);

    QDate getSeniority() const;
    quint64 getSeniorityInDays() const;
    static QDate getTotalSeniority(std::unique_ptr<std::vector<Seniority>> seniorityData);

};