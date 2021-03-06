#include "widget.h"
#include <QtWidgets>
#include "stdafx.h"

#include "Employee.h"
#include "File.h"
#include "Position.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
Widget::Widget(QWidget *parent)
	: QWidget(parent)


{	
	ADD_EMPLOYEE = new QPushButton(QString::fromLocal8Bit("&ADD_EMPLOYEE �������� ����������"));
	DEL_EMPLOYEE = new QPushButton(QString::fromLocal8Bit("&DEL_EMPLOYEE ������� ����������"));
	CHANGE_POSITION = new QPushButton(QString::fromLocal8Bit("&CHANGE_POSITION �������� ��� ����������"));
	ASSOCIATE_EMPLOYEE = new QPushButton(QString::fromLocal8Bit("&����������� ���������� � ���������"));
	SORT_LASTNAME = new QPushButton(QString::fromLocal8Bit("&����������� ������ �� ��������"));
	SORT_DATE = new QPushButton(QString::fromLocal8Bit("&����������� ����� �������� �� ������"));
	PRINT_EMPLYEES_LIST = new QPushButton(QString::fromLocal8Bit("&PRINT_EMPLYEES_LIST������� ������ ����������"));
	GET_LIST_ASSOCIATE = new QPushButton(QString::fromLocal8Bit("&������� ������ ���������� ���������� � ���������"));
	EXIT = new QPushButton(QString::fromLocal8Bit("&�����"));

	QObject::connect(PRINT_EMPLYEES_LIST, &QPushButton::clicked, this, &Widget::PRINT_EMPLYEES_LISTBtnClicked);



	//lst << "First" << "Second" << "Third" << "Second" << "Third";
	tbl = new QTableWidget(n,n);
/*       tbl->setHorizontalHeaderLabels(lst);
	   tbl->setVerticalHeaderLabels(lst);

	   for (int i  = 0; i < 5; ++i) {
		   for (int j = 0; j < 5; ++j) {
			   ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
			   tbl->setItem(i, j, ptwi);
		   }
	   }
	   */
	tbl->resize(400, 400);



	//Layout setup
	pvbxLayout = new QVBoxLayout;
	pvbxLayout->addWidget(tbl);
	pvbxLayout->addWidget(ADD_EMPLOYEE);
	pvbxLayout->addWidget(DEL_EMPLOYEE);
	pvbxLayout->addWidget(CHANGE_POSITION);
	pvbxLayout->addWidget(ASSOCIATE_EMPLOYEE);
	pvbxLayout->addWidget(SORT_LASTNAME);
	pvbxLayout->addWidget(SORT_DATE);
	pvbxLayout->addWidget(PRINT_EMPLYEES_LIST);
	pvbxLayout->addWidget(GET_LIST_ASSOCIATE);
	pvbxLayout->addWidget(EXIT);
	setLayout(pvbxLayout);

	File2 ftemp;

	ftemp.ReadEmplyeesList(company2);
	PRINT_EMPLYEES_LISTBtnClicked();
}

Widget::~Widget()
{

}

void Widget::PRINT_EMPLYEES_LISTBtnClicked()
{
	{
		QStringList lst;
		lst << QString::fromLocal8Bit("���") << QString::fromLocal8Bit("�������");

		tbl->setHorizontalHeaderLabels(lst);
	}

	std::vector< Employee2* > emplyeesVec = company2.GetEmployees();

	tbl->setColumnCount(2);
	tbl->setRowCount(emplyeesVec.size());

	QTableWidgetItem* ptwi = nullptr;

	for (int i = 0; i < emplyeesVec.size(); ++i) {

		ptwi = new QTableWidgetItem(QString::fromStdString( emplyeesVec[i]->GetFirstName() ) );
		tbl->setItem(i, 0, ptwi);

		ptwi = new QTableWidgetItem(QString::fromStdString(emplyeesVec[i]->GetLastName()));
		tbl->setItem(i, 1, ptwi);
	}
}
