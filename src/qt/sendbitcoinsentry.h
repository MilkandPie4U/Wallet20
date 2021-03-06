#ifndef SENDBITCOINSENTRY_H
#define SENDBITCOINSENTRY_H

#include <QFrame>

namespace Ui {
    class SendBitCoinsEntry;
}
class WalletModel;
class SendCoinsRecipient;

/** A single entry in the dialog for sending bitcoins. */
class SendBitCoinsEntry : public QFrame
{
    Q_OBJECT

public:
    explicit SendBitCoinsEntry(QWidget *parent = 0);
    ~SendBitCoinsEntry();

    void setModel(WalletModel *model);
    bool validate();
    SendCoinsRecipient getValue();

    /** Return whether the entry is still empty and unedited */
    bool isClear();

    void setValue(const SendCoinsRecipient &value);
    void setAddress(const QString &address);
    /** Set up the tab chain manually, as Qt messes up the tab chain by default in some cases (issue https://bugreports.qt-project.org/browse/QTBUG-10907).
     */
    QWidget *setupTabChain(QWidget *prev);

    void setFocus();

public slots:
    void setRemoveEnabled(bool enabled);
    void clear();

signals:
    void removeEntry(SendBitCoinsEntry *entry);
    void payAmountChanged();

private slots:
    void on_deleteButton_clicked();
    void on_payTo_textChanged(const QString &address);
    void on_addressBookButton_clicked();
    void on_pasteButton_clicked();
    void updateDisplayUnit();

private:
    Ui::SendBitCoinsEntry *ui;
    WalletModel *model;
};

#endif // SENDBITCOINSENTRY_H
