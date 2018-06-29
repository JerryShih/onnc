#ifndef ONNX_BM1880_TGCONCAT_H
#define ONNX_BM1880_TGCONCAT_H

#include "BM188xComputeOperator.h"
#include <onnc/Target/TG/BM188x/common_calibration2.pb.h>
#include <onnx/common/ir.h>

namespace onnc {
namespace BM188X {

// m_MemOperands: input, output
class TGConcat : public BM188xComputeOperator
{
public:
  TGConcat(const ::onnx::Node &pNode);

  void emit() const override;
  void print(OStream &pOS) const override;
  TGConcat *addMemOperands(std::vector<MemOperand *> &pInput,
                           MemOperand *pOutput);
  void toASM(tg::bm1880::Inst *pI) const override;
  void
  update(const tg::bm1880::LayerCalibrationParameter *pLayerCtable) override
  {
    return;
  }

private:
  std::vector<unsigned long int> m_InputAddr;
  std::vector<int> m_InputDims;
  std::vector<int> m_OutputDim;
  int m_ConcatAxis;
};

} // namespace BM188X
} // namespace onnc

#endif