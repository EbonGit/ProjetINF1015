#include "GestionnaireStatus.h"

void GestionnaireStatus::sendMessage(std::string title, std::string msg, int level) {
	emit emitMessage(title, msg, level);
}

void GestionnaireStatus::setStatus(std::string status) {
	emit updateStatus(status);
}