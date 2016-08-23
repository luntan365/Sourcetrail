#include "component/view/DialogView.h"

DialogView::DialogView()
{
}

DialogView::~DialogView()
{
}

void DialogView::showProgressDialog(const std::string& title, const std::string& message)
{
}

void DialogView::hideProgressDialog()
{
}

bool DialogView::startIndexingDialog(size_t cleanFileCount, size_t indexFileCount)
{
	return false;
}

void DialogView::updateIndexingDialog(size_t fileCount, size_t totalFileCount, std::string sourcePath)
{
}

void DialogView::finishedIndexingDialog(size_t fileCount, size_t totalFileCount, float time, ErrorCountInfo errorInfo)
{
}

int DialogView::confirm(const std::string& message)
{
	return confirm(message, std::vector<std::string>());
}

int DialogView::confirm(const std::string& message, const std::vector<std::string>& options)
{
	return -1;
}
