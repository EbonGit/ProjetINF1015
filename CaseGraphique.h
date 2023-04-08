#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QLayout>
#include <QButtonGroup>


class CaseGraphique : public QPushButton
{
	Q_OBJECT;

public:
	CaseGraphique(int, QWidget* parent = nullptr);
	~CaseGraphique() override = default;

	char get_side() { return side_; };
private:
	int side_;
};
