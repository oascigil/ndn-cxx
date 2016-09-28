
#include "hash-tags.hpp"

namespace ndn {                                                                          
  
template<encoding::Tag TAG>
size_t                                                                                   
HashTags::wireEncode(EncodingImpl<TAG>& encoder) const                                
{ 
  size_t totalLength = prependStringBlock(encoder, tlv::HashTags, m_hashtags);     
  return totalLength;                                                                    
}                                                                                        
  
template size_t
HashTags::wireEncode<encoding::EncoderTag>(EncodingImpl<encoding::EncoderTag>& encoder) const;
  
template size_t                                                                          
HashTags::wireEncode<encoding::EstimatorTag>(EncodingImpl<encoding::EstimatorTag>& encoder) const;

void
HashTags::wireDecode(const Block& wire)                                               
{ 
  if (wire.type() != tlv::HashTags)                                                   
    BOOST_THROW_EXCEPTION(tlv::Error("Unexpected TLV type when decoding HashTags"));  
                                                                                         
  m_htBlock = wire;                                                                      
  m_hashtags = readString(wire);                                                      
                                                                                         
}

std::string
HashTags::getTags() const
{
  return m_hashtags;
}

} // namespace ndn                                  
