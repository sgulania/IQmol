#ifndef IQMOL_DATA_NMRREFERENCE_H
#define IQMOL_DATA_NMRREFERENCE_H
/*******************************************************************************

  Copyright (C) 2011-2013 Andrew Gilbert

  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.

  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.

  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************************/

#include "DataList.h"


namespace IQmol {
namespace Data {

   class NmrReference : public Base {

      friend class boost::serialization::access;

      public:

         NmrReference(QString const& system = QString(), 
                      QString const& method = QString(), 
                      QString const& basis  = QString() ) : m_method(method) { }

         Type::ID typeID() const { return Type::NmrReference; }

         void setMethod(QString const& method) { m_method = method; }
         void setSystem(QString const& system) { m_system = system; }
         void setBasis(QString const&  basis)  { m_basis  = basis; }

         void addElement(QString const& symbol, double const shfit, double const offset);
         double shift(QString const& symbol) const;

         void dump() const;

         void serialize(InputArchive& ar, unsigned int const version = 0) {
            Q_UNUSED(version);
            ar & m_method;
            ar & m_system;
            ar & m_basis;
            ar & m_shifts;
         }

         void serialize(OutputArchive& ar, unsigned int const version = 0) {
            Q_UNUSED(version);
            ar & m_method;
            ar & m_system;
            ar & m_basis;
            ar & m_shifts;
         }

      private:
         QString m_method;
         QString m_system;
         QString m_basis;

         QMap<QString, double> m_shifts;
   };

   typedef Data::List<Data::NmrReference> NmrReferenceList;

} } // end namespace IQmol::Data

#endif
