#pragma once



class AppController {
public:
    explicit AppController(QObject *parent = nullptr);

    bool save();

private:
    void currentState(bool &titled, bool &modified);

};
