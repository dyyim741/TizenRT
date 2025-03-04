/****************************************************************************
 *
 * Copyright 2019 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * include/video/video.h
 *
 *   Copyright 2018 Sony Semiconductor Solutions Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Sony Semiconductor Solutions Corporation nor
 *    the names of its contributors may be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
/**
 * @file video.h
 */

#ifndef __MODULES_INCLUDE_VIDEO_VIDEO_H
#define __MODULES_INCLUDE_VIDEO_VIDEO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <stdint.h>
#include <sys/ioctl.h>
#include <video/video_controls.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup video Video driver
 * @{ */
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define _VIDIOCBASE   (0x1000)

#define _VIDIOC(nr)       _IOC(_VIDIOCBASE, nr)

/**
 * @defgroup video_ioctl IOCTL commands
 * @{
 */

/**
 * Enumerate the formats supported by device
 *
 * @param[in/out] arg
 * Address pointing to struct #v4l2_fmtdesc
 */

#define VIDIOC_ENUM_FMT               _VIDIOC(0x0001)

/**
 * Enumerate the framesizes supported by device
 *
 * @param[in/out] arg
 * Address pointing to struct #v4l2_frmsizeenum
 */

#define VIDIOC_ENUM_FRAMESIZES        _VIDIOC(0x0002)

/**
 * Enumerate the frameintervals supported by device
 *
 * @param[in/out] arg
 * Address pointing to struct #v4l2_frmivalenum
 */

#define VIDIOC_ENUM_FRAMEINTERVALS    _VIDIOC(0x0003)

/**
 * Try format
 *
 * @param[in/out] arg
 * Address pointing to struct #v4l2_try_pix_format
 */

#define VIDIOC_TRY_FMT                _VIDIOC(0x0004)

/**
 * Set the data format.
 *
 * @param[in] arg
 * Address pointing to struct #v4l2_format
 */

#define VIDIOC_S_FMT                  _VIDIOC(0x0005)

/**
 * Set the frame interval.
 *
 * @param[in] arg
 * Address pointing to struct #v4l2_streamparm
 */

#define VIDIOC_S_PARM                 _VIDIOC(0x0006)

/**
 * Initiate user pointer I/O
 *
 * @param[in] arg
 * Address pointing to struct #v4l2_requestbuffers
 */

#define VIDIOC_REQBUFS                _VIDIOC(0x0007)

/**
 * Enqueue an empty buffer
 *
 * @param[in] arg
 * Address pointing to struct #v4l2_buffer
 */

#define VIDIOC_QBUF                   _VIDIOC(0x0008)

/**
 * Dequeue a filled buffer
 *
 * @param[out] arg
 * Address pointing to struct #v4l2_buffer
 */

#define VIDIOC_DQBUF                  _VIDIOC(0x0009)

/**
 * Start streaming
 *
 * @param[in] arg
 * Address pointing to enum #v4l2_buf_type
 */

#define VIDIOC_STREAMON               _VIDIOC(0x000A)

/**
 * Stop streaming
 *
 * @param[in] arg
 * Address pointing to enum #v4l2_buf_type
 */

#define VIDIOC_STREAMOFF              _VIDIOC(0x000B)

/**
 * Do halfpush
 *
 * @param[in] arg
 * Address pointing to bool
 */

#define VIDIOC_DO_HALFPUSH            _VIDIOC(0x000C)

/**
 * Start taking picture
 *
 * @param[in] arg
 * The number of times the picture is taken.
 * Type is int32_t, not address pointer.\n
 * 0 or negative value means continuing until VIDIOC_TAKEPICT_STOP. \n
 * Positive value(to be supported) means continuing
 * up to a specified number of times  or until VIDIOC_TAKEPICT_STOP.
 */

#define VIDIOC_TAKEPICT_START         _VIDIOC(0x000D)

/**
 * Stop taking picture
 *
 * @param[in] arg
 * Address pointing to bool
 */

#define VIDIOC_TAKEPICT_STOP          _VIDIOC(0x000E)

/**
 * Query control
 *
 * @param[in] arg
 * Address pointing to struct #v4l2_queryctrl
 */

#define VIDIOC_QUERYCTRL              _VIDIOC(0x000F)

/**
 * Query control
 *
 * @param[in] arg
 * Address pointing to struct #v4l2_query_ext_ctrl
 */

#define VIDIOC_QUERY_EXT_CTRL         _VIDIOC(0x0010)

/** Query menu
 *
 * @param[in] arg
 * Address pointing to struct #v4l2_querymenu
 */

#define VIDIOC_QUERYMENU              _VIDIOC(0x0011)

/** Get current control value.
 *  This request is a special case of VIDIOC_G_EXT_CTRLS.
 *  @param[in] arg
 *  Address pointing to struct #v4l2_control
 */

#define VIDIOC_G_CTRL                 _VIDIOC(0x0012)

/** Set control value.
 *  This request is a special case of VIDIOC_S_EXT_CTRLS.
 *  @param[in] arg
 *  Address pointing to struct #v4l2_control
 */

#define VIDIOC_S_CTRL                 _VIDIOC(0x0013)

/** Get current control value
 *  @param[in] arg
 *  Address pointing to struct #v4l2_ext_controls
 */

#define VIDIOC_G_EXT_CTRLS            _VIDIOC(0x0014)

/** Set control value
 *  @param[in] arg
 *  Address pointing to struct #v4l2_ext_controls
 */

#define VIDIOC_S_EXT_CTRLS            _VIDIOC(0x0015)

/** Cancel DQBUF
 *  @param[in] arg
 *  enum #v4l2_buf_type
 */

#define VIDIOC_CANCEL_DQBUF           _VIDIOC(0x0016)

/** @} video_ioctl */

/**
 * @defgroup video_defs Defines
 * @{
 */

#define VIDEO_HSIZE_QVGA        (320)	/**< QVGA    horizontal size */
#define VIDEO_VSIZE_QVGA        (240)	/**< QVGA    vertical   size */
#define VIDEO_HSIZE_VGA         (640)	/**< VGA     horizontal size */
#define VIDEO_VSIZE_VGA         (480)	/**< VGA     vertical   size */
#define VIDEO_HSIZE_QUADVGA     (1280)	/**< QUADVGA horizontal size */
#define VIDEO_VSIZE_QUADVGA     (960)	/**< QUADVGA vertical   size */
#define VIDEO_HSIZE_HD          (1280)	/**< HD      horizontal size */
#define VIDEO_VSIZE_HD          (720)	/**< HD      vertical   size */
#define VIDEO_HSIZE_FULLHD      (1920)	/**< FULLHD  horizontal size */
#define VIDEO_VSIZE_FULLHD      (1080)	/**< FULLHD  vertical   size */
#define VIDEO_HSIZE_5M          (2560)	/**< 5M      horizontal size */
#define VIDEO_VSIZE_5M          (1920)	/**< 5M      vertical   size */
#define VIDEO_HSIZE_3M          (2048)	/**< 3M      horizontal size */
#define VIDEO_VSIZE_3M          (1536)	/**< 3M      vertical   size */

/**  Four-character-code (FOURCC) */
#define v4l2_fourcc(a, b, c, d)\
	((uint32_t)(a)        | ((uint32_t)(b) << 8) | \
	((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))
#define v4l2_fourcc_be(a, b, c, d)    (v4l2_fourcc(a, b, c, d) | (1 << 31))

/** YUV 4:2:2 */

#define V4L2_PIX_FMT_UYVY v4l2_fourcc('U', 'Y', 'V', 'Y')

/** RGB565 */

#define V4L2_PIX_FMT_RGB565 v4l2_fourcc('R', 'G', 'B', 'P')

/** JFIF JPEG */

#define V4L2_PIX_FMT_JPEG v4l2_fourcc('J', 'P', 'E', 'G')

/** JPEG + sub image */

#define V4L2_PIX_FMT_JPEG_WITH_SUBIMG v4l2_fourcc('J', 'S', 'U', 'B')

/** MAX length of v4l2_fmtdesc description string */

#define V4L2_FMT_DSC_MAX       (32)

/** MAX length of v4l2_query_ext_ctrl dims array */

#define V4L2_CTRL_MAX_DIMS     (4)

/** MAX value of VIDIOC_REQBUFS count parameter */

#define V4L2_REQBUFS_COUNT_MAX (256)

/** Buffer error flag */

#define V4L2_BUF_FLAG_ERROR    (0x0001)

/** @} video_defs */

/****************************************************************************
 * Public Types
 ****************************************************************************/
/**
 * @defgroup video_datatypes Data types
 * @{
 */

/** Buffer type.
 *  Currently, support only V4L2_BUF_TYPE_VIDEO_CAPTURE and
 *  V4L2_BUF_TYPE_STILL_CAPTURE.
 */

enum v4l2_buf_type {
	V4L2_BUF_TYPE_VIDEO_CAPTURE = 1,	   /**< single-planar video capture stream */
	V4L2_BUF_TYPE_VIDEO_OUTPUT = 2,		   /**< single-planar video output stream */
	V4L2_BUF_TYPE_VIDEO_OVERLAY = 3,	   /**< video overlay */
	V4L2_BUF_TYPE_VBI_CAPTURE = 4,		   /**< raw VBI capture stream */
	V4L2_BUF_TYPE_VBI_OUTPUT = 5,		   /**< raw VBI output stream */
	V4L2_BUF_TYPE_SLICED_VBI_CAPTURE = 6,  /**< sliced VBI capture stream */
	V4L2_BUF_TYPE_SLICED_VBI_OUTPUT = 7,   /**< sliced VBI output stream */
	V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY = 8,/**< video output overlay  */
	V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE = 9,/**< multi-planar video capture stream */
	V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE = 10,/**< multi-planar video output stream */
	V4L2_BUF_TYPE_SDR_CAPTURE = 11,		   /**< Software Defined Radiocapture stream */
	V4L2_BUF_TYPE_SDR_OUTPUT = 12,		   /**< Software Defined Radio output stream */
	V4L2_BUF_TYPE_META_CAPTURE = 13,	   /**< metadata capture */
	V4L2_BUF_TYPE_PRIVATE = 0x80,		   /**< Deprecated, do not use */
	V4L2_BUF_TYPE_STILL_CAPTURE = 0x81	   /**< single-planar still capture stream */
};

/** Memory I/O method. Currently, support only V4L2_MEMORY_USERPTR. */

enum v4l2_memory {
	V4L2_MEMORY_MMAP = 1,	 /**< memory mapping I/O */
	V4L2_MEMORY_USERPTR = 2, /**< user pointer I/O  */
	V4L2_MEMORY_OVERLAY = 3, /**< overlay I/O */
	V4L2_MEMORY_DMABUF = 4,	 /**< DMA shared buffer I/O */
};

/** Field order. Currently, support only V4L2_FIELD_ANY */

enum v4l2_field {
	V4L2_FIELD_ANY = 0,		     /**< driver can choose from none, */
	V4L2_FIELD_NONE = 1,	     /**< this device has no fields ... */
	V4L2_FIELD_TOP = 2,		     /**< top field only */
	V4L2_FIELD_BOTTOM = 3,	     /**< bottom field only */
	V4L2_FIELD_INTERLACED = 4,   /**< both fields interlaced */
	V4L2_FIELD_SEQ_TB = 5,	     /**< both fields sequential into one */
	V4L2_FIELD_SEQ_BT = 6,	     /**< same as above + bottom-top order */
	V4L2_FIELD_ALTERNATE = 7,    /**< both fields alternating into */
	V4L2_FIELD_INTERLACED_TB = 8,/**< both fields interlaced, top field */
	V4L2_FIELD_INTERLACED_BT = 9,/**< both fields interlaced, top field */
};

/** Buffer mode */

enum v4l2_buf_mode {
	V4L2_BUF_MODE_RING = 0, /**< Ring structure */
	V4L2_BUF_MODE_FIFO = 1, /**< FIFO structure */
};

/** @struct v4l2_requestbuffers
 *  @brief  parameter of ioctl(VIDIOC_REQBUFS)
 */

struct v4l2_requestbuffers {
	uint32_t count; /**< The number of buffers requested. Supported maximum value is V4L2_REQBUFS_COUNT_MAX(=256) */
	uint32_t type;  /**< enum #v4l2_buf_type */
	uint32_t memory;/**< enum #v4l2_memory */
	uint32_t mode;  /**< enum #v4l2_buf_mode */
};
typedef struct v4l2_requestbuffers v4l2_requestbuffers_t;

struct v4l2_timecode {
	uint32_t type;
	uint32_t flags;
	uint8_t frames;
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t userbits[4];
};
typedef struct v4l2_timecode v4l2_timecode_t;

struct v4l2_plane {
	uint32_t bytesused;
	uint32_t length;
	union {
		uint32_t mem_offset;
		unsigned long userptr;
		int fd;
	} m;
	uint32_t data_offset;
	uint32_t reserved[11];
};
typedef struct v4l2_plane v4l2_plane_t;

/** @struct v4l2_buffer
 *  @brief  Parameter of ioctl(VIDIOC_QBUF) and ioctl(VIDIOC_DQBUF). \n
 *          Currently, support only index, type, bytesused, memory,
 *          m.userptr, and length.
 */

struct v4l2_buffer {
	uint16_t index;			      /**< buffer id */
	uint16_t type;			      /**< enum #v4l2_buf_type */
	uint32_t bytesused;		      /**< Driver sets the image size */
	uint16_t flags;			      /**< buffer flags. V4L2_BUF_FLAG_ERROR is set in error case. */
	uint16_t field;			      /**< the field order of the image */
	struct v4l2_timecode timecode;/**< frame timecode */
	uint16_t sequence;		      /**< frame sequence number */
	uint16_t memory;		      /**< enum #v4l2_memory */
	union {
		uint32_t offset;
		unsigned long userptr;    /**< address of buffer */
		struct v4l2_plane *planes;
		int fd;
	} m;
	uint32_t length;		       /**< user set the buffer size */
};
typedef struct v4l2_buffer v4l2_buffer_t;

/** @struct v4l2_fmtdesc
 *  @brief  parameter of ioctl(VIDIOC_ENUM_FMT)
 */

struct v4l2_fmtdesc {
	uint16_t index;						/**< Format number      */
	uint16_t type;						/**< enum v4l2_buf_type */
	uint32_t flags;
	char description[V4L2_FMT_DSC_MAX];	/**< Description string */
	uint32_t pixelformat;				/**< Format fourcc      */
	uint32_t subimg_pixelformat;		/**< Format fourcc      */
};

enum v4l2_frmsizetypes {
	V4L2_FRMSIZE_TYPE_DISCRETE = 1,	 /**< Discrete value */
	V4L2_FRMSIZE_TYPE_CONTINUOUS = 2,/**< Continous value */
	V4L2_FRMSIZE_TYPE_STEPWISE = 3,	 /**< Step value */
};

struct v4l2_frmsize_discrete {
	uint16_t width;	   /**< Frame width [pixel] */
	uint16_t height;   /**< Frame height [pixel] */
};

struct v4l2_frmsize_stepwise {
	uint16_t min_width;   /**< Minimum frame width [pixel] */
	uint16_t max_width;   /**< Maximum frame width [pixel] */
	uint16_t step_width;  /**< Frame width step size [pixel] */
	uint16_t min_height;  /**< Minimum frame height [pixel] */
	uint16_t max_height;  /**< Maximum frame height [pixel] */
	uint16_t step_height; /**< Frame height step size [pixel] */
};

/** @struct v4l2_frmsizeenum
 *  @brief  parameter of ioctl(VIDIOC_ENUM_FRAMESIZES)
 */

struct v4l2_frmsizeenum {
	uint32_t index;			/**< Frame size number */
	uint32_t buf_type;		/**< enum #v4l2_buf_type */
	uint32_t pixel_format;	/**< Pixel format */
	uint32_t type;			/**< Frame size type the device supports. */
	union {					/**< Frame size */
		struct v4l2_frmsize_discrete discrete; /**< Use in type = V4L2_FRMSIZE_TYPE_DISCRETE case */
		struct v4l2_frmsize_stepwise stepwise;
		/**< Use in type = V4L2_FRMSIZE_TYPE_CONTINUOUS or V4L2_FRMSIZE_TYPE_STEPWISE case */
	};
	uint32_t subimg_pixel_format;
	/**< Pixel format of sub image */
	uint32_t subimg_type;	 /**< Frame size type of subimage. */

	union {					 /** Frame size of subimage */
		struct v4l2_frmsize_discrete discrete;
		/**< Use in subimg_type = V4L2_FRMSIZE_TYPE_DISCRETE case */
		struct v4l2_frmsize_stepwise stepwise;
		/**< Use in subimg_type = V4L2_FRMSIZE_TYPE_CONTINUOUS or V4L2_FRMSIZE_TYPE_STEPWISE case */
	} subimg;
};

/** type of frame interval enumeration */

enum v4l2_frmivaltypes {
	V4L2_FRMIVAL_TYPE_DISCRETE = 1,	 /**< Discrete value */
	V4L2_FRMIVAL_TYPE_CONTINUOUS = 2,/**< Continuous value */
	V4L2_FRMIVAL_TYPE_STEPWISE = 3,	 /**< Step value */
};

/** Fraction */

struct v4l2_fract {
	uint32_t numerator;				  /**< numerator */
	uint32_t denominator;			  /**< denominator */
};

/** frame interval enumeration with stepwise format */

struct v4l2_frmival_stepwise {
	struct v4l2_fract min;			  /**< Minimum frame interval [s] */
	struct v4l2_fract max;			  /**< Maximum frame interval [s] */
	struct v4l2_fract step;			  /**< Frame interval step size [s] */
};

/** @struct v4l2_frmivalenum
 *  @brief  parameter of ioctl(VIDIOC_ENUM_FRAMEINTERVALS)
 */

struct v4l2_frmivalenum {
	uint32_t index;			/**< Frame format index */
	uint32_t buf_type;		/**< enum #v4l2_buf_type */
	uint32_t pixel_format;	/**< Pixel format */
	uint16_t width;			/**< Frame width */
	uint16_t height;		/**< Frame height */
	uint32_t subimg_pixel_format; /**< Pixel format for sub image */
	uint16_t subimg_width;	/**< Frame width  for sub image */
	uint16_t subimg_height;	/**< Frame height for sub image */
	uint32_t type;			/**< Frame interval type */
	union {					/**< Frame interval */
		struct v4l2_fract discrete;
		struct v4l2_frmival_stepwise stepwise;
	};
};

/** Single-planar format structure. */

struct v4l2_pix_format {
	uint16_t width;			/**< Image width in pixels */
	uint16_t height;		/**< Image height in pixels */
	uint32_t pixelformat;	/**< The pixel format or type of compression. V4L2_PIX_FMT_UYVY or V4L2_PIX_FMT_JPEG or V4L2_PIX_FMT_JPEG_WITH_SUBIMG */
	uint16_t subimg_width;	/**< sub image width in pixels in case of pixelformat = V4L2_PIX_FMT_JPEG_WITH_SUBIMG */
	uint16_t subimg_height;	/**< sub image height in pixels in case of pixelformat = V4L2_PIX_FMT_JPEG_WITH_SUBIMG */
	uint32_t subimg_pixelformat; /**< The pixel format of sub imagein case of pixelformat = V4L2_PIX_FMT_JPEG_WITH_SUBIMG */
	uint32_t field;			/**< enum #v4l2_field */
	uint32_t bytesperline;	/**< for padding, zero if unused */
	uint32_t sizeimage;		/**< Size in bytes of the buffer to hold a complete image */
	uint32_t colorspace;	/**< Image colorspace */
	uint32_t priv;			/**< private data, depends on pixelformat */
	uint32_t flags;			/**< format flags (V4L2_PIX_FMT_FLAG_*) */
	union {
		uint32_t ycbcr_enc;	/**< enum v4l2_ycbcr_encoding */
		uint32_t hsv_enc;	/**< enum v4l2_hsv_encoding */
	};
	uint32_t quantization;	/**< enum v4l2_quantization */
	uint32_t xfer_func;		/**< enum v4l2_xfer_func */
};
typedef struct v4l2_pix_format v4l2_pix_format_t;

/** @struct v4l2_format
 *  @brief  parameter of ioctl(VIDIOC_S_FMT)
 */

struct v4l2_format {
	uint32_t type;			/**< enum #v4l2_buf_type. */
	union {
		struct v4l2_pix_format pix;
		/**< image format */
	} fmt;
};
typedef struct v4l2_format v4l2_format_t;

struct v4l2_captureparm {
	uint32_t capability;	/*  Supported modes */
	uint32_t capturemode;	/*  Current mode */
	struct v4l2_fract timeperframe;	/*  Time per frame in seconds */
	uint32_t extendedmode;	/*  Driver-specific extensions */
	uint32_t readbuffers;	/*  # of buffers for read */
};

/** @struct v4l2_streamparm
 *  @brief  parameter of ioctl(VIDIOC_S_PARM)
 */

struct v4l2_streamparm {
	uint32_t type;			/* enum v4l2_buf_type */
	union {
		struct v4l2_captureparm capture;
//    struct v4l2_outputparm  output;
	} parm;
};

/** Control type.
 */
enum v4l2_ctrl_type {
	V4L2_CTRL_TYPE_INTEGER = 1,
	V4L2_CTRL_TYPE_BOOLEAN = 2,
	V4L2_CTRL_TYPE_MENU = 3,
	V4L2_CTRL_TYPE_BUTTON = 4,
	V4L2_CTRL_TYPE_INTEGER64 = 5,
	V4L2_CTRL_TYPE_CTRL_CLASS = 6,
	V4L2_CTRL_TYPE_STRING = 7,
	V4L2_CTRL_TYPE_BITMASK = 8,
	V4L2_CTRL_TYPE_INTEGER_MENU = 9,
	V4L2_CTRL_TYPE_U8FIXEDPOINT_Q7 = 10,
	V4L2_CTRL_TYPE_U16FIXEDPOINT_Q8 = 11,
	V4L2_CTRL_TYPE_INTEGER_TIMES_3 = 12,

	/* Compound types are >= 0x0100 */
	V4L2_CTRL_COMPOUND_TYPES = 0x0100,
	V4L2_CTRL_TYPE_U8 = 0x0100,
	V4L2_CTRL_TYPE_U16 = 0x0101,
	V4L2_CTRL_TYPE_U32 = 0x0102,
};

/** @struct v4l2_queryctrl
 *  @brief  parameter of ioctl(VIDIOC_QUERYCTRL)
 */

struct v4l2_queryctrl {
	uint16_t ctrl_class;		   /**< Control class */
	uint16_t id;				   /**< Control id */
	uint16_t type;				   /**< enum #v4l2_ctrl_type */
	char name[32];				   /**< Name of control */
	int32_t minimum;			   /**< Minimum value */
	int32_t maximum;			   /**< Maximum value */
	uint32_t step;				   /**< step */
	int32_t default_value;		   /**< Default value */
	uint32_t flags;				   /**< Flag */
};

/** @struct v4l2_query_ext_ctrl
 *  @brief  parameter of ioctl(VIDIOC_QUERY_EXT_CTRL)
 */

struct v4l2_query_ext_ctrl {
	uint16_t ctrl_class;		   /**< Control class */
	uint16_t id;				   /**< Control id */
	uint16_t type;				   /**< enum #v4l2_ctrl_type */
	char name[32];				   /**< Name of control */
	int64_t minimum;			   /**< Minimum value */
	int64_t maximum;			   /**< Maximum value */
	uint64_t step;				   /**< step */
	int64_t default_value;		   /**< Default value */
	uint32_t flags;				   /**< Flag */
	uint32_t elem_size;			   /**< size of each element */
	uint32_t elems;				   /**< number of elements */
	uint32_t nr_of_dims;		   /**< number of dimensions */
	uint32_t dims[V4L2_CTRL_MAX_DIMS];
	/**< Dimensions */
};

/** @struct v4l2_querymenu
 *  @brief  parameter of ioctl(VIDIOC_QUERYMENU)
 */

struct v4l2_querymenu {
	uint16_t ctrl_class;/**< camera control class */
	uint16_t id;		/**< camera control id    */
	uint32_t index;		/**< index of menu.       */
	union {
		char name[32];	/**< name of menu  */
		int64_t value;	/**< value of menu */
	};
} __attribute__((packed));

/** @struct v4l2_control
 *  @brief  parameter of ioctl(VIDIOC_G_CTRL / VIDIOC_S_CTRL)
 */

struct v4l2_control {
	uint16_t id;
	int32_t value;
};

/** structure for each control of
 *  ioctl(VIDIOC_G_EXT_CTRLS / VIDIOC_S_EXT_CTRLS)
 */

struct v4l2_ext_control {
	uint16_t id;   /**< camera control id */
	uint16_t size; /**< size of value(not use) */
	union {
		int32_t value;
		/**< QUERY_EXT_CTRL type = INTEGER, xxx */
		int64_t value64;
		/**< QUERY_EXT_CTRL type = INTEGER64, MENU */
		char *string;
		uint8_t *p_u8;
		/**< QUERY_EXT_CTRL type = U8  */
		uint16_t *p_u16;
		/**< QUERY_EXT_CTRL type = U16 */
		uint32_t *p_u32;
		/**< QUERY_EXT_CTRL type = U32 */
		void *ptr;
	};
} __attribute__((packed));

/** @struct v4l2_ext_controls
 *  @brief  parameter of ioctl(VIDIOC_G_EXT_CTRLS / VIDIOC_S_EXT_CTRLS)
 */

struct v4l2_ext_controls {
	union {
		uint16_t ctrl_class;	       /**< camera control class        */
		uint16_t which;
	};
	uint16_t count;				       /**< number of requests          */
	uint16_t error_idx;			       /**< index in that error occured */
	struct v4l2_ext_control *controls; /**< each control information    */
};

/** @} video_datatypes */

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/


#ifdef __cplusplus
}
#endif
#endif							/* __MODULES_INCLUDE_VIDEO_VIDEO_H */
