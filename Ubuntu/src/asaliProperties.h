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

#ifndef ASALIPROPERTIES_H
#define ASALIPROPERTIES_H

#include <gtkmm.h>
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
    class asaliProperties : public Gtk::Window
    {
        public:
            asaliProperties();
            
            void destroy();
            void build();
            void savedMessage();
            void set_type(const std::string type);
            void set_n(const std::vector<std::string> n);
            void set_reactions(const std::vector<std::vector<std::string> > name,
                               const std::vector<std::vector<int> >         stoich);
            void set_energy(const std::string energy);
                               

            void doneInput();
            void convertToCaption(std::string& n);

            std::vector<double>  get_MW()   {return MW_;};
            std::vector<double>  get_diff() {return diff_;};
            std::vector<double>  get_Q()    {return Q_;};
            
            double               get_cp()   {return cp_;};
            double               get_cond() {return cond_;};
            
            std::vector<double>  get_mass_fraction(const std::vector<double> MW, const std::vector<double> x);
            std::vector<double>  get_mole_fraction(const std::vector<double> MW, const std::vector<double> y);
            double               get_MWmix(const std::vector<double> MW, const std::vector<double> x);


            virtual ~asaliProperties();
            
        private:
        
            std::string       getBeer();
        
            Gtk::Image        batchLogo_;
            Gtk::Image        ph1dLogo_;

            Gtk::Box          mainBox_;
            Gtk::Box          heatBox_;
            Gtk::Box          diffBox_;

            Gtk::Grid         mainGrid_;
            Gtk::Grid         cpGrid_;
            Gtk::Grid         condGrid_;

            Gtk::Label        nameLabel_;
            Gtk::Label        mwLabel_;
            Gtk::Label        diffLabel_;
            Gtk::Label        reactionLabel_;
            Gtk::Label        heatLabel_;
            Gtk::Label        cpLabel_;
            Gtk::Label        condLabel_;
            
            Gtk::Button       doneButton_;
            
            Gtk::ComboBoxText heatCombo_;
            Gtk::ComboBoxText cpCombo_;
            Gtk::ComboBoxText condCombo_;
            Gtk::ComboBoxText diffCombo_;

            Gtk::Entry          cpEntry_;
            Gtk::Entry          condEntry_;
            
            std::vector<Gtk::Label *>   speciesNameLabel_;
            std::vector<Gtk::Label *>   reactionNumberLabel_;

            std::vector<Gtk::Entry *>   speciesMwEntry_;
            std::vector<Gtk::Entry *>   speciesDiffEntry_;
            std::vector<Gtk::Entry *>   speciesHeatEntry_;
            
            
            unsigned int              NR_;
            unsigned int              NC_;
            
            std::vector<std::string>  n_;
            std::vector<std::string>  beer_;
            std::vector<std::string>  small;
            std::vector<std::string>  big;
            
            std::vector<double>       MW_;
            std::vector<double>       diff_;
            std::vector<double>       Q_;
            

            std::string               type_;
            std::string               energy_;
            
            double                    cp_;
            double                    cond_;

            std::vector<std::vector<std::string> > name_;
            std::vector<std::vector<int> >         stoich_;

    };
}

#endif