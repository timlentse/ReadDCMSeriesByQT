/**
@ simple software for reading DICM slices
@author；timlentse
@email: tinglenxan@gmail.com
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("A program for reading DICM series"));
    ui->toolBar->setFixedHeight(30);
    readerDCMSeries = vtkSmartPointer<vtkDICOMImageReader>::New();
    imageViewerDCMSeriesX = vtkSmartPointer<vtkImageViewer2>::New();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QFileDialog *Dialg=  new  QFileDialog(this,  tr("choose a dictionary include DICOM files"),  "D:/",   tr("All Files (*);;Dicom Files (*.dcm)"));
    Dialg->setFileMode(QFileDialog::DirectoryOnly);
    if (Dialg->exec()== QFileDialog::Accepted)
    {
     QStringList Filelist= Dialg->selectedFiles();
     std::string stdstrFolderNameDCM =Filelist.at(0).toUtf8().constData();
     drawDCMSeries(stdstrFolderNameDCM);
    }

}

void MainWindow::drawDCMSeries(std::string folderDCM)
{
    readerDCMSeries->SetDirectoryName(folderDCM.c_str());
    readerDCMSeries->Update();
    readerDCMSeries->GetOutput()->GetScalarRange(rangescalar);
    //滑动条的初始化
    ui->horizontalSlider->setMaximum(static_cast<int>(rangescalar[1]));
    ui->spinBox->setMaximum(static_cast<int>(rangescalar[1]));
    ui->horizontalSlider->setMinimum(static_cast<int>(rangescalar[0]));
    ui->spinBox->setMinimum(static_cast<int>(rangescalar[0]));
    ui->horizontalSlider_2->setMaximum(static_cast<int>(2*(rangescalar[1]-rangescalar[0])+1));
    ui->spinBox_3->setMaximum(static_cast<int>(2*(rangescalar[1]-rangescalar[0])+1));

    imageViewerDCMSeriesX->SetInputConnection(readerDCMSeries->GetOutputPort());
    mMinSliderX = imageViewerDCMSeriesX->GetSliceMin();
    mMaxSliderX = imageViewerDCMSeriesX->GetSliceMax();
    ui->hSliderDCM->setMinimum(mMinSliderX);
    ui->hSliderDCM->setMaximum(mMaxSliderX);

    imageViewerDCMSeriesX->SetSlice(1);
    imageViewerDCMSeriesX->SetupInteractor(ui->vtkRenderer->GetRenderWindow()->GetInteractor());
    ui->vtkRenderer->SetRenderWindow(imageViewerDCMSeriesX->GetRenderWindow());
    imageViewerDCMSeriesX->Render();
}

void MainWindow::on_hSliderDCM_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    imageViewerDCMSeriesX->SetSlice(value);
    imageViewerDCMSeriesX->Render();
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
      ui->hSliderDCM->setValue(arg1);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
      ui->spinBox->setValue(value);
      imageViewerDCMSeriesX->SetColorLevel(value);
      imageViewerDCMSeriesX->Render();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    imageViewerDCMSeriesX->SetColorWindow(value);
    imageViewerDCMSeriesX->Render();
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}


void MainWindow::on_actionOpen_triggered()
{
    QFileDialog *Dialg=  new  QFileDialog(this,
                                           tr("choose a dictionary include DICOM files"),
                                           "D:/",
                                           tr("All Files (*);;Dicom Files (*.dcm)"));
    Dialg->setFileMode(QFileDialog::DirectoryOnly);
    if (Dialg->exec()== QFileDialog::Accepted)
    {
     QStringList Filelist= Dialg->selectedFiles();
     std::string stdstrFolderNameDCM =Filelist.at(0).toUtf8().constData();
     drawDCMSeries(stdstrFolderNameDCM);
    }
}
