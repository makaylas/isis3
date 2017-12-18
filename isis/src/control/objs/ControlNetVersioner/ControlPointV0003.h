#ifndef ControlPointV0003_h
#define ControlPointV0003_h
/**
 * @file
 * $Revision: 1.9 $
 * $Date: 2009/07/15 17:33:52 $
 *
 *   Unless noted otherwise, the portions of Isis written by the USGS are
 *   public domain. See individual third-party library and package descriptions
 *   for intellectual property information, user agreements, and related
 *   information.
 *
 *   Although Isis has been used by the USGS, no warranty, expressed or
 *   implied, is made by the USGS as to the accuracy and functioning of such
 *   software and related material nor shall the fact of distribution
 *   constitute any such warranty, and no responsibility is assumed by the
 *   USGS in connection therewith.
 *
 *   For additional information, launch
 *   $ISISROOT/doc//documents/Disclaimers/Disclaimers.html
 *   in a browser or see the Privacy &amp; Disclaimers page on the Isis website,
 *   http://isis.astrogeology.usgs.gov, and the USGS privacy and disclaimers on
 *   http://www.usgs.gov/privacy.html.
 */

 #include <QSharedPointer>

 #include "QSharedPointer<ControlPointFileEntryV0002>.pb.h"

namespace Isis {
  class ControlPointV0002;
  class PvlObject;

  //TODO document this
  class ControlPointV0003 {
    public:
      ControlPointV0003(const PvlObject &pointObject);
      ControlPointV0003(QSharedPointer<ControlPointFileEntryV0002> pointData);
      ControlPointV0003(ControlPointV0002 &oldPoint);

      QSharedPointer<ControlPointFileEntryV0002> pointData();

    private:
      // These are intentionally not implemented
      ControlPointV0003();
      ControlPointV0003(const &ControlPointV0003 other);
      ControlPointV0003 &operator=(const &ControlPointV0003 other);

      // methods for converting from Pvl to protobuf
      void copy(PvlContainer &container,
                QString keyName,
                QSharedPointer<ControlPointFileEntryV0002> point,
                void (ControlPointFileEntryV0002::*setter)(bool));
      void copy(PvlContainer &container,
                QString keyName,
                QSharedPointer<ControlPointFileEntryV0002> &point,
                void (ControlPointFileEntryV0002::*setter)(double));
      void copy(PvlContainer &container,
                QString keyName,
                QSharedPointer<ControlPointFileEntryV0002> &point,
                void (ControlPointFileEntryV0002::*setter)(const std::string&));
      void copy(PvlContainer &container,
                QString keyName,
                ControlPointFileEntryV0002::Measure &measure,
                void (ControlPointFileEntryV0002::Measure::*setter)(bool));
      void copy(PvlContainer &container,
                QString keyName,
                ControlPointFileEntryV0002::Measure &measure,
                void (ControlPointFileEntryV0002::Measure::*setter)(double));
      void copy(PvlContainer &container,
                QString keyName,
                ControlPointFileEntryV0002::Measure &measure,
                void (ControlPointFileEntryV0002::Measure::*setter)(const std::string &));

      QSharedPointer<ControlPointFileEntryV0002> m_pointData; /**< protobuf container that holds
                                                                   information used to create a
                                                                   control point.*/
  };
}

#endif
