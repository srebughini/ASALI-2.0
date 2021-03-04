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

#ifndef PYTHONINTERFACE_H
#define PYTHONINTERFACE_H

#include <Python.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>


namespace ASALI
{
    /// Class to estimate homogenous and heterogeneous reaction rates from python file
    class pythonInterface
    {
        public:
            /// Class constructor
            pythonInterface();

            /// Set temperature in [K]
            void setTemperature(const double T);
            
            /// Set mole fraction
            void setMoleFraction(const std::vector<double> x,const std::vector<std::string> name);
            
            /// Convert string from lower case to upper case
            void convertToCaption(std::string& n);

            /// Initialize PyObject
            std::string initialize(const std::string function, const std::string path);
            
            /// Estimate species homogeneous and heterogeneous reaction rates
            void run();
            
            /// Estimate species homogeneous reaction rates
            void runHomogeneous();
            
            /// Estimate species heterogeneous reaction rates
            void runHeterogeneous();
            
            /// Estimate homogeneous reaction rates
            void runAllHomogeneous();
            
            /// Estimate heterogeneous reaction rates
            void runAllHeterogeneous();
            
            /// Estimate net homogeneous reaction rates
            void runNetHomogeneous();
            
            /// Estimate net heterogeneous reaction rates
            void runNetHeterogeneous();
            
            /// Destroy PyObject
            void close();

            /// Return species heterogeneous reaction rates
            std::vector<double>      getHetReactionRate()  {return Rhet_;};
            
            /// Return species homogeneous reaction rates
            std::vector<double>      getHomReactionRate()  {return Rhom_;};
            
            /// Return net heterogeneous reaction rates
            std::vector<double>      getHetNetRate()       {return RhetNet_;};
            
            /// Return net homogeneous reaction rates
            std::vector<double>      getHomNetRate()       {return RhomNet_;};
            
            /// Return species names
            std::vector<std::string> getSpeciesName()      {return n_;};

            /// Check single species name
            int                      checkNames(std::string name);
            
            /// Check species names
            std::vector<int>         checkNames(std::vector<std::string> &name);
            
            /// Return number of homogeneous reactions
            unsigned int             getNumberOfHomReactions() {return Nhom_;};
            
            /// Return number of heterogeneous reactions
            unsigned int             getNumberOfHetReactions() {return Nhet_;};
            
            /// Return number of heterogeneous and homogeneous reactions
            unsigned int             getNumberOfReactions()    {return (Nhet_+Nhom_);};

            /// Return heterogeneous reaction rates
            std::vector<std::vector<double> >  getAllHetReactionRate()  {return RallHet_;};
            
            /// Return homogeneous reaction rates
            std::vector<std::vector<double> >  getAllHomReactionRate()  {return RallHom_;};

            /// Class destructor 
            virtual ~pythonInterface();
            
        private:

            std::vector<double> Rhet_;
            std::vector<double> Rhom_;
            std::vector<double> RhetNet_;
            std::vector<double> RhomNet_;
            
            std::vector<std::string> n_;
            std::vector<std::string> small;
            std::vector<std::string> big;
            
            unsigned int Nhet_;
            unsigned int Nhom_;
            
            std::vector<std::vector<double> > RallHet_;
            std::vector<std::vector<double> > RallHom_;

            PyObject *pModule;
            PyObject *pClass;
            PyObject *pInstance;
            PyObject *pName;
            PyObject *pNhom;
            PyObject *pNhet;
            PyObject *pHomReaction;
            PyObject *pHetReaction;
            PyObject *pAllHomReaction;
            PyObject *pAllHetReaction;
            PyObject *pHomNet;
            PyObject *pHetNet;
            PyObject *pArgs;
            PyObject *pTemperature;
            PyObject *pMassFraction;
            PyObject *pHomReactionRate;
            PyObject *pHetReactionRate;
            PyObject *pAllHomReactionRate;
            PyObject *pAllHetReactionRate;
            PyObject *pHomNetRate;
            PyObject *pHetNetRate;
    };
}

#endif