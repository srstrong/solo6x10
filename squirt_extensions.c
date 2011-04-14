#include <media/v4l2-ioctl.h>
#include <media/v4l2-common.h>

#include "solo6010.h"
#include "squirt_extensions.h"

static void set_qp(struct solo_enc_dev *solo_enc, int qp)
{
  u8 ch = solo_enc->ch;
  struct solo6010_dev *solo_dev = solo_enc->solo_dev;

  solo_enc->qp = qp;

  solo_reg_write(solo_dev, SOLO_VE_CH_QP(ch), solo_enc->qp);

  /* Extended encoding only */
  solo_reg_write(solo_dev, SOLO_VE_CH_QP_E(ch), solo_enc->qp);
}

long squirtbox_ioctl(struct file *file, void *priv, int cmd, void *arg)
{
  struct solo_enc_fh *fh = priv;
  struct solo_enc_dev *solo_enc = fh->enc;

  switch (cmd)
    {
    case SB_SET_QP:
      set_qp(solo_enc, *((int *)arg));
    }

  return 0;
}

