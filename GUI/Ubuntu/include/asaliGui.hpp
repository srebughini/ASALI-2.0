/*##############################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software: you can redistribute it and/or modify                              #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
##############################################################################################*/

#include "pythonInterface.hpp"
#include "speciesPopup.hpp"
#include "transportProperties.hpp"
#include "thermoProperties.hpp"
#include "thermoTransportProperties.hpp"
#include "vacuumProperties.hpp"
#include "linearRegression.hpp"
#include "asaliKineticMaker.hpp"
#include <gtk/gtk.h>
#include <filesystem>

#if ASALI_USING_CANTERA==1
#include "chemkinConverter.hpp"
#include "canteraInterface.hpp"
#include "catalyticPellet.hpp"
#include "equilibriumCalculator.hpp"
#include "batchReactor.hpp"
#include "cstrReactor.hpp"
#include "ph1dReactor.hpp"
#include "het1dReactor.hpp"
#include "pressureDrops.hpp"
#else
#include "asaliInterface.hpp"
#endif

namespace ASALI
{
    class asaliGui : public Gtk::Window
    {
        public:
            asaliGui();
            
            virtual ~asaliGui();
            
            #include "shared/UnitConversion.H"
            #include "shared/FileManager.H"
            
        private:

            void exit();
            void createChemistryInterface();
            void discrimer();
            void mainMenu();
            void noneInputError();
            void changeCursor();
            void defaultCanteraInput();
            void noneInput();
            void kineticAsali();
            void kineticMake();
            void kineticCheck();
            void chemistryMenu2();
            void transport();
            void thermo();
            void thermoTransport();
            void vacuum();
            void linearRegression();

            bool chemistryMenu1(GdkEventButton*);
            
            #if ASALI_USING_CANTERA==1
            void chemkin();
            void loadCanteraInput();
            void equilibrium();
            void pellets();
            void reactors();
            void batch();
            void cstr();
            void ph1d();
            void het1d();
            void dp();
            #endif

            std::string       getBeer();
            std::string       getBeerShort();
            
            std::vector<std::string> splitString(const std::string txt, std::string ch);

            Gtk::Button       discrimerButton_;
            Gtk::Button       exitButton1_;
            Gtk::Button       exitButton2_;
            Gtk::Button       exitButton3_;
            Gtk::Button       exitButton4_;
            Gtk::Button       exitButton5_;
            Gtk::Button       backButton1_;
            Gtk::Button       backButton2_;
            Gtk::Button       startButton_;
            Gtk::Button       defaultCanteraInputButton_;
            Gtk::Button       loadCanteraInputButton_;
            Gtk::Button       noneInputButton_;
            Gtk::Button       conversionButton_;
            Gtk::Button       canteraInputButton_;
            Gtk::Button       transportButton_;
            Gtk::Button       thermoButton_;
            Gtk::Button       thermoTransportButton_;
            Gtk::Button       equilibriumButton_;
            Gtk::Button       linearRegressionButton_;
            Gtk::Button       reactorsButton_;
            Gtk::Button       vacuumButton_;
            Gtk::Button       pelletButton_;
            Gtk::Button       batchButton_;
            Gtk::Button       cstrButton_;
            Gtk::Button       ph1dButton_;
            Gtk::Button       het1dButton_;
            Gtk::Button       dpButton_;
            Gtk::Button       asaliKineticButton_;
            Gtk::Button       asaliKineticMakeButton_;
            Gtk::Button       asaliKineticCheckButton_;
            
            Gtk::Box          menuBox_;
            Gtk::Box          chemistryBox_;
            Gtk::Box          reactorBox_;
            Gtk::Box          kineticBox_;

            
            Gtk::ButtonBox    linkButtonBox_;
            Gtk::ButtonBox    exitButtonBox_;
            Gtk::ButtonBox    discrimerButtonBox_;
            Gtk::ButtonBox    startButtonBox_;
            Gtk::ButtonBox    chemistryButtonBox_;
            Gtk::ButtonBox    menuButtonBox_;
            Gtk::ButtonBox    reactorButtonBox_;
            Gtk::ButtonBox    kineticButtonBox_;

            Gtk::EventBox     logoEventBox_;

            Gtk::Label        heading_;
            Gtk::Label        kineticLabel_;
            Gtk::Label        beerLabel_;

            Gtk::Grid         grid_;
            Gtk::Grid         reactorButtonGrid_;
            Gtk::Grid         kineticButtonGrid_;

            Gtk::Image        bigLogo_;
            Gtk::Image        smallLogo1_;
            Gtk::Image        smallLogo2_;
            Gtk::Image        smallLogo3_;
            Gtk::Image        smallLogo4_;
            
            Gtk::LinkButton   gitButton_;
            Gtk::LinkButton   forgeButton_;
            
            std::string       kineticType_;

            std::vector<std::string>  beer_;
            std::vector<std::string>  beerShort_;


            ASALI::speciesPopup               *speciesNames_;
            ASALI::transportProperties        *transportMenu_;
            ASALI::thermoProperties           *thermoMenu_;
            ASALI::thermoTransportProperties  *thermoTransportMenu_;
            ASALI::vacuumProperties           *vacuumMenu_;
            ASALI::linearRegression           *linearRegressionMenu_;
            ASALI::asaliKineticMaker          *asaliKineticMakerMenu_;

            #if ASALI_USING_CANTERA==1
            ASALI::chemkinConverter           *converter_;
            ASALI::canteraInterface           *chemistryInterface_;
            ASALI::equilibriumCalculator      *equilibriumMenu_;
            ASALI::batchReactor               *batchMenu_;
            ASALI::cstrReactor                *cstrMenu_;
            ASALI::ph1dReactor                *ph1dMenu_;
            ASALI::het1dReactor               *het1dMenu_;
            ASALI::pressureDrops              *dpMenu_;
            ASALI::catalyticPellet            *pelletMenu_;

            Cantera::ThermoPhase              *thermo_;
            Cantera::Transport                *transport_;
            Cantera::Kinetics                 *kinetic_;
            Cantera::ThermoPhase              *surface_;
            Cantera::Kinetics                 *surface_kinetic_;
            #else
            ASALI::asaliInterface             *chemistryInterface_;
            #endif
    };
}
