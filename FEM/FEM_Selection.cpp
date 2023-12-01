/* *****************************************************************************
Copyright (c) 2016-2021, The Regents of the University of California (Regents).
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE CoPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS
PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

*************************************************************************** */

// Written by: Frank McKenna
#include <FEM_Selection.h>
#include <OpenSeesFEM.h>
#include <OpenSeesPyFEM.h>
#include <FEAPpvFEM.h>
#include <CustomFEM.h>
#include <surrogateGpFEM.h>
#include <SimCenterAppMulti.h>
#include <NoneWidget.h>


FEM_Selection::FEM_Selection(bool inclMulti, QWidget *parent)
  : SimCenterAppSelection(QString("FEM"), QString("FEM"), parent)
{
    SimCenterAppWidget *opensees = new OpenSeesFEM();
    SimCenterAppWidget *openseesPy = new OpenSeesPyFEM();
    SimCenterAppWidget *FEAPpv = new FEAPpvFEM();
    SimCenterAppWidget *surrogateGp = new surrogateGpFEM();
    SimCenterAppWidget *customFEM = new CustomFEM();

    this->addComponent(QString("OpenSees"), QString("OpenSees"), opensees);
    this->addComponent(QString("Python"), QString("OpenSeesPy"), openseesPy);
    this->addComponent(QString("FEAPpv"), QString("FEAPpv"), FEAPpv);
    this->addComponent(QString("SurrogateGP"), QString("SurrogateGP"), surrogateGp);
    this->addComponent(QString("Custom"), QString("Custom"), customFEM);
//    this->addComponent(QString("None"), QString("None"), new SimCenterAppWidget());
    this->addComponent(QString("None"), QString("None"), new NoneWidget());

    if (inclMulti == true) {
      SimCenterAppWidget *multi = new SimCenterAppMulti(QString("FEM"), QString("MultiModel-FEM"),this, this);
      this->addComponent(QString("Multi Model"), QString("MultiModel"), multi);
    }
}


FEM_Selection::~FEM_Selection()
{

}

SimCenterAppWidget *
FEM_Selection::getClone()
{
  FEM_Selection *newSelection = new FEM_Selection(false);
  return newSelection;
}




