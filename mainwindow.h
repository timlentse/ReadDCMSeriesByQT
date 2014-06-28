#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include<vtkImageData.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkActor2D.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <QDir>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void drawDCMSeries(std::string folderDCM);

    void on_hSliderDCM_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_3_valueChanged(int arg1);

    void on_action_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    vtkSmartPointer<vtkDICOMImageReader> readerDCMSeries;
    vtkSmartPointer<vtkImageViewer2> imageViewerDCMSeriesX;
    int mMinSliderX;
    int mMaxSliderX;
    double rangescalar[2];
};

#endif // MAINWINDOW_H
