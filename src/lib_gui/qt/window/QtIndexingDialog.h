#ifndef QT_INDEXING_WIZARD_WINDOW_H
#define QT_INDEXING_WIZARD_WINDOW_H

#include "qt/window/QtWindow.h"

class QLabel;
class QtProgressBar;

class QtIndexingDialog
	: public QtWindow
{
	Q_OBJECT

public:
	enum DialogType
	{
		DIALOG_MESSAGE,
		DIALOG_PROGRESS,
		DIALOG_INDEXING
	};

	QtIndexingDialog(QWidget* parent = 0);
	QSize sizeHint() const override;

	DialogType getType() const;

	void setupStart(size_t cleanFileCount, size_t indexFileCount, std::function<void(bool)> callback);
	void setupProgress();
	void setupIndexing();
	void setupReport(size_t fileCount, size_t totalFileCount, float time);

	void updateMessage(QString message);
	void updateIndexingProgress(size_t fileCount, size_t totalFileCount, std::string sourcePath);
	void updateErrorCount(size_t errorCount, size_t fatalCount);

protected:
	void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;

	virtual void handleNext() override;
	virtual void handleClose() override;

private:
	void setType(DialogType type);

	QBoxLayout* createLayout();
	void addTopAndProgressBar(float topRatio);
	void addTitle(QString title, QBoxLayout* layout);

	void addPercentLabel(QBoxLayout* layout);
	void addMessageLabel(QBoxLayout* layout);
	void addFilePathLabel(QBoxLayout* layout);
	void addErrorLabel(QBoxLayout* layout);

	void addButtons(QBoxLayout* layout);
	void addFlag();

	void setGeometries();
	void finishSetup();

	DialogType m_type;

	QWidget* m_top;
	float m_topRatio;
	QtProgressBar* m_progressBar;

	QLabel* m_percentLabel;
	QLabel* m_messageLabel;
	QLabel* m_filePathLabel;
	QPushButton* m_errorLabel;

	QSize m_sizeHint;

	std::function<void(bool)> m_callback;
	QString m_sourcePath;
};

#endif // QT_INDEXING_WIZARD_WINDOW_H
