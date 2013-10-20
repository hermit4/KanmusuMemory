/*
 * Copyright 2013 KanMemo Project.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef WEBPAGEFORM_H
#define WEBPAGEFORM_H

#include <QWidget>
#include <QtCore/QUrl>
#include <QWebPage>

namespace Ui {
class WebPageForm;
}

class WebPageForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit WebPageForm(QWidget *parent = 0);
    ~WebPageForm();

    
    QUrl url() const;
    void setUrl(const QUrl &url);
    void setWebPage(QWebPage *webpage);
    QString title() const;
    bool isMobileMode() const;
    void setMobileMode(bool mobileMode);

    void reload();
    void makeNewWebPage(QWebPage *webpage);

    void find();

signals:
    void urlChanged();
    void addTabRequested(QWebPage *webpage);
    void removeTabRequested(WebPageForm *form);
    void updateFavorite();

private:
    class Private;
    Private *d;

    bool m_mobileMode;
};

#endif // WEBPAGEFORM_H