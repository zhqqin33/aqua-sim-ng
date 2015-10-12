
//...

#include "aqua-sim-packetstamp.h"
#include "ns3/log.h"

namespace ns3{

NS_LOG_COMPONENT_DEFINE("AquaSimPacketStamp");
NS_OBJECT_ENSURE_REGISTERED(AquaSimPacketStamp);


AquaSimPacketStamp::AquaSimPacketStamp(void) : m_pt(-1), m_pr(-1),
m_txRange(-1), m_freq(-1), m_noise(0) 
{
}

TypeId
AquaSimPacketStamp::GetTypeId(void)
{
  static TypeId tid = TypeId("ns3::AquaSimPacketStamp")
    ;
  return tid;
}

bool
AquaSimPacketStamp::CheckConflict(void)
{
  return (m_txRange > 0 && m_pt < 0) || (m_txRange < 0 && m_pt > 0);
}

void
AquaSimPacketStamp::Stamp(Packet * p, double pt, double pr)
{
  m_pt = pt;
  m_pr = pr;
}


}  //namespace ns3