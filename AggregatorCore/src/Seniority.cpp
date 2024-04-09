#include "Seniority.h"





// Seniority Data





SeniorityData::SeniorityData() { }
SeniorityData::SeniorityData(const QDate &first, const QDate &last) :
    m_firstDate{first}, 
    m_lastDate{last} 
{ }

SeniorityData::SeniorityData(QDate &&first, QDate &&last) :
    m_firstDate{std::move(first)}, 
    m_lastDate{std::move(last)} 
{ }

SeniorityData::~SeniorityData() { }





bool operator==(const SeniorityData &d1, const SeniorityData &d2) 
{
    if (d1.m_firstDate == d2.m_firstDate && d1.m_lastDate == d2.m_lastDate)
        return true;
    return false;
}

bool operator!=(const SeniorityData &d1, const SeniorityData &d2) {
    return !(d1 == d2);
}





QJsonObject SeniorityData::toJson() const
{
    QJsonObject json;
    json["firstDate"] = m_firstDate.toJulianDay();
    json["lastDate"] = m_lastDate.toJulianDay();
    return json;
}

SeniorityData SeniorityData::fromJson(const QJsonObject &&json)
{
    SeniorityData data;

    if (const QJsonValue v = json["firstDate"]; v.isDouble())
        data.m_firstDate = QDate::fromJulianDay(json["firstDate"].toInt());

    if (const QJsonValue v = json["lastDate"]; v.isDouble())
        data.m_firstDate = QDate::fromJulianDay(json["lastDate"].toInt());

    return data;
}






QPair<QDate, QDate> SeniorityData::getDatesPair() const 
{
    return QPair<QDate, QDate>(m_firstDate, m_lastDate);
}





// Seniority Data Handler






Seniority::Seniority(QDate &&firstDate, QDate &&lastDate)
{
    m_data = SeniorityData(firstDate, lastDate); 
    m_calculateSeniority();
}

Seniority::Seniority(const QDate &firstDate, const QDate &lastDate)
{ 
    m_data = SeniorityData(firstDate, lastDate); 
    m_calculateSeniority();
}

Seniority::~Seniority() { }





bool Seniority::m_calculateSeniority()
{
    std::unique_ptr<QPair<QDate, QDate>> dates = 
        std::make_unique<QPair<QDate, QDate>>(m_data.getDatesPair());
    
    if(dates == nullptr || dates.get() == nullptr)
        return false;

    m_seniorityInDays = dates->first.daysTo(dates->second);
    m_seniority = m_seniority.addDays(m_seniorityInDays);

    return true;
}





QDate Seniority::getSeniority() const 
{
    return m_seniority;
}

quint64 Seniority::getSeniorityInDays() const 
{
    return m_seniorityInDays;
}

QDate Seniority::getTotalSeniority(
    std::unique_ptr<std::vector<Seniority>> seniorityData) 
{
    QDate returnValue;
    quint64 days;
    
    if(seniorityData == nullptr)\
        return QDate(9999, 9, 9);

    for(auto c : *seniorityData.get())
    {
        days += c.getSeniorityInDays();
    }

    return returnValue.addDays(days);
}