/**
  * @file player.h
  * @brief audio and video player
  * @author Agapova Ekaterina
  */
#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStandardItemModel>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Player; }
QT_END_NAMESPACE

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = nullptr);
    ~Player();

private:
    Ui::Player *ui;
    QStandardItemModel *model;
    QVideoWidget *widget;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    int m_sound = 50;
    qint64 player_duration;
    QMap <QUrl, qint64> map;

private:
    /**
     * @brief set ToolButton style
     */
    void setButtonStyle();
    /**
     * @brief setPlaylist
     */
    void setPlaylist();
    /**
     * @brief set videoWidget
     */
    void videoWidget();
    /**
     * @brief set sound
     */
    void setSound();
    /**
     * @brief set duration
     */
    void setDuration();
    /**
     * @brief save position to map
     */
    void savePosition();
    /**
     * @brief read position from map
     */
    void readPosition();
    /**
     * @brief save map to file
     */
    void saveMap();
    /**
     * @brief read map from file
     */
    void readMap();

private slots:
    /**
     * @brief play
     */
    void play();
    /**
     * @brief next
     */
    void next();
    /**
     * @brief pause
     */
    void pause();
    /**
     * @brief stop
     */
    void stop();
    /**
     * @brief addFile
     */
    void addFile();
    /**
     * @brief deleteFile
     */
    void deleteFile();
    /**
     * @brief soundChange
     * @param sound
     */
    void soundChange(QString sound);
    /**
     * @brief soundMute
     */
    void soundMute();
    /**
     * @brief durationChanged
     * @param duration
     */
    void durationChanged(qint64 duration);
    /**
     * @brief positionChanged
     * @param progress
     */
    void positionChanged(qint64 progress);
    /**
     * @brief seek
     * @param seconds
     */
    void seek(int seconds);
    /**
     * @brief updateDurationInfo
     * @param currentInfo
     */
    void updateDurationInfo(qint64 currentInfo);
};
#endif // PLAYER_H
