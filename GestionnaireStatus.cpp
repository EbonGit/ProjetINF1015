#include "GestionnaireStatus.h"

void GestionnaireStatus::setStatus(std::string status) {
	statusMessage_ = status;
	emit updateStatus(status);
}