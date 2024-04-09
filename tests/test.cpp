#include "gtest/gtest.h"
#include "Hash.h"
#include "Seniority.h"
#include <QString>
#include <QHash>
#include <qdebug.h>




// HASH TESTSTTSTSTS





TEST(HashTest, Numbers)
{
    ASSERT_EQ(
        Hash::hash(QString("123")),
        QString("3c9909afec25354d551dae21590bb26e38d53f2173b8d3dc3eee4c047e7ab1c1eb8b85103e3be7ba613b31bb5c9c36214dc9f14a42fd7a2fdb84856bca5c44c2").toUtf8()
    );
}

TEST(HashTest, WierdText)
{
    ASSERT_EQ(
        Hash::hash(QString("123аб 12")),
        QString("dd79d5f2d1349052e7f2b7c1b155e2a7a960915aeeccc274dbfe7786e7779e924007b6776f656990d063a6a1f9d48f9997443c2ba1b9f8d1aa4c10f444cc19ca").toUtf8()
    );
}

TEST(HashTest, Emoji)
{
    ASSERT_EQ(
        Hash::hash(QString("😃 😄 😅 😆")),
        QString("f803e7518764411cba6be37c628716c25a93485ae2caef5b6bb12d8e6028651255f030f8e9ea1acd8986412ed2eaaa4ca1778d486896638c13ea92972775fdd5").toUtf8()
    );
}

TEST(HashTest, NoText)
{
    ASSERT_EQ(Hash::hash(""), QString().toUtf8());
}

TEST(HashTest, TextIsEmpty)
{
    ASSERT_EQ(Hash::hash(QString()), QString().toUtf8());
}





// Seniority tests




TEST(SeniorityTest, OperatorCorrectness)
{
    SeniorityData s1;
    SeniorityData s2;

    SeniorityData s3(s1);
    SeniorityData s4(QDate(1987, 12, 3), QDate(1997, 12, 3));
    
    ASSERT_TRUE(s1 == s2);
    ASSERT_TRUE(s3 == s2 && s3 == s1);
    ASSERT_FALSE(s3 == s4);
    ASSERT_TRUE(s3 != s4);
}

