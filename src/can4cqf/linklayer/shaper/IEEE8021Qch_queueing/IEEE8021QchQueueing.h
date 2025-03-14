//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __CAN4CQF_IEEE8021QCHQUEUEING_H_
#define __CAN4CQF_IEEE8021QCHQUEUEING_H_

#include <omnetpp.h>
// 导入
#include "core4inet/linklayer/shaper/IEEE8021Qbv/selection/IEEE8021QbvSelection.h"
using namespace omnetpp;
using namespace std;

namespace CAN4CQF {

/**
 * @brief 从queue接收报文，并发送到对应的门，对于untagged的报文，添加默认VLAN标签
 */
class IEEE8021QchQueueing : public cSimpleModule
{
    /**
     * @brief Number of priorities.
     */
    unsigned int numPCP;
    /**
     * @brief Default priority for frames without PCP.
     */
    unsigned int defaultPCP;
    /**
     * @brief Untagged VLAN.
     * Untagged incoming frames get tagged with this VLAN. Outgoing frames with this VLAN get untagged.
     */
    uint16_t untaggedVID;
    /**
     * @brief Tagged VLANs.
     * Only outgoing frames with one of the VLANs in this list are transmitted. Default is "0" to allow for untagged frames
     */
    std::vector<int> taggedVIDs;

  protected:
    /**
     * @brief Initializes the module.
     */
    virtual void initialize();
    /**
     * @brief Indicates a parameter has changed.
     *
     * @param parname Name of the changed parameter or nullptr if multiple parameter changed.
     */
    virtual void handleParameterChange(const char* parname);
    /**
     * @brief Handles the incoming message of the IEEE 802.1Qbv transmission selection.
     *
     * @param msg incoming inet::EtherFrame.
     */
    virtual void handleMessage(cMessage *msg);
};


} //namespace

#endif
