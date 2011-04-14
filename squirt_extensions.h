#ifndef __SQUIRT_EXTENSIONS_H
#define __SQUIRT_EXTENSIONS_H

#define SB_SET_QP _IOWR('V', BASE_VIDIOC_PRIVATE, int)

enum solo_enc_types {
	SOLO_ENC_TYPE_STD,
	SOLO_ENC_TYPE_EXT,
};

struct solo_enc_fh {
	struct			solo_enc_dev *enc;
	u32			fmt;
	u8			enc_on;
	enum solo_enc_types	type;
	struct videobuf_queue	vidq;
	struct list_head	vidq_active;
	int			desc_count;
	int			desc_nelts;
        struct solo_p2m_desc	*desc_items;
	dma_addr_t		desc_dma;
	struct list_head	list;
};

struct solo_videobuf {
	struct videobuf_buffer	vb;
	unsigned int		flags;
};


extern long squirtbox_ioctl(struct file *file, void *fh, int cmd, void *arg);

extern long squirt_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

#endif
