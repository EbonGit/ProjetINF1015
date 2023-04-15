#pragma once
#include<QObject>
#include<string>

class GestionnaireStatus : public QObject
{
	Q_OBJECT

public:
	GestionnaireStatus() = default;
	void sendMessage(std::string, std::string, int level=0);
	void setStatus(std::string);
	std::string getCurrentStatus() { return statusMessage_; };

signals:
	void emitMessage(std::string, std::string, int);
	void updateStatus(std::string);

private :
	std::string statusMessage_;
};

