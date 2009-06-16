/***************************************************************************
 *   Copyright (C) 2008 by Simon Andreas Eugster (simon.eu@gmail.com)      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef UNICODEDIALOG_H
#define UNICODEDIALOG_H

#include "ui_unicodedialog_ui.h"

class UnicodeDialog : public QDialog, public Ui::UnicodeDialog_UI
{
	Q_OBJECT
	
public:
	/** \brief The input method for the dialog. Atm only InputHex supported. */
	enum InputMethod { InputHex, InputDec };
	
	UnicodeDialog(InputMethod inputMeth);
	~UnicodeDialog();
	
	/** \brief Returns infos about an unicode number. Extendable/improvable ;) */
	QString unicodeInfo(QString unicode_number);

private:
	Ui::UnicodeDialog_UI m_view;
	
	/** Selected input method */
	InputMethod inputMethod;
	/** \brief Validates text and removes all invalid characters (non-hex e.g.) */
	QString validateText(QString text);
	
	int lastCursorPos;
	QString lastUnicodeNumber;

signals:
	/** \brief Contains the selected unicode character; emitted when Enter is pressed. */
	void charSelected(const QString&);

private slots:
	void slotTextChanged(QString text);
	void slotReturnPressed();

};

#endif
