#ifndef NDN_HASHTAGS_HPP
#define NDN_HASHTAGS_HPP 

#include "encoding/block.hpp"                                                            
#include "encoding/block-helpers.hpp"                                                    
                                                                                         
namespace ndn {                                                                          
                                                                                         
class HashTags
{

public:                                                                                  
  
  /**
   * @brief Create a new HashTags object with no components.                                 
   */
  HashTags()
  : m_htBlock(tlv::HashTags)                                                          
  {                                                                                      
  }
  
  HashTags(std::string ht)
  : m_hashtags(ht)
  {
  }

  template<encoding::Tag TAG>                                                            
  size_t
  wireEncode(EncodingImpl<TAG>& encoder) const;                                          

  void                                                                                   
  wireDecode(const Block& wire);

  std::string
  getTags() const;

private:
  mutable Block m_htBlock;                                                               
  std::string m_hashtags;
};

} // namespace ndn  


#endif
