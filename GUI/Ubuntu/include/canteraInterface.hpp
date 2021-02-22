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

#ifndef CANTERAINTERFACE_H
#define CANTERAINTERFACE_H
#include "cantera/Interface.h"
#include "cantera/thermo.h"
#include "cantera/transport.h"
#include "cantera/kinetics.h"
#include "cantera/transport/TransportData.h"
#include "basicInterface.hpp"

namespace ASALI
{
    class canteraInterface : public ASALI::basicInterface
    {
        public:
            canteraInterface(Cantera::ThermoPhase* thermo,
                             Cantera::Transport*   transport);

            virtual void setMoleFraction(const std::vector<double> x,const std::vector<std::string> name);
            virtual void setMassFraction(const std::vector<double> y,const std::vector<std::string> name);
            virtual void thermoCalculate();
            virtual void transportCalculate();
            virtual void vacuumCalculate();
            virtual void equilibriumCalculate(std::string type);
            virtual void convertToCaption(std::string& n);
            
            virtual double temperature();
            virtual double density();

            virtual std::vector<int>  checkNames(std::vector<std::string>& name);
            virtual int               checkNames(std::string name);
            virtual int               numberOfSpecies();

            virtual ~canteraInterface();
            
        private:

            Cantera::ThermoPhase* thermo_;
            Cantera::Transport*   transport_;
    };
}

#endif