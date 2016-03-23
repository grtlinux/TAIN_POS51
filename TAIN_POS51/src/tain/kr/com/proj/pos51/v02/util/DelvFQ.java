/**
 * Copyright 2014, 2015, 2016 TAIN, Inc. all rights reserved.
 *
 * Licensed under the GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.gnu.org/licenses/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------
 * Copyright 2014, 2015, 2016 TAIN, Inc.
 *
 */
package tain.kr.com.proj.pos51.v02.util;

import java.io.RandomAccessFile;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : DelvFQ.java
 *   -. Package    : tain.kr.com.proj.pos51.v02.util
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 22. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class DelvFQ {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(DelvFQ.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private static final String REC_FILE_NAME = "POSHW000003";
	
	private String fileName = null;
	private String delvName = null;
	private int recCnt = -1;
	
	private RandomAccessFile raf = null;
	private String line = null;
	private byte[] byLine = null;
	private int recSeq = -1;
	private int delvSeq = -1;
	private long pos = -1;
	private int recLen = -1;

	private String strDate = null;
	private String strTime = null;
	
	public DelvFQ(String fileName, String delvName, int recCnt) throws Exception {
		
		if (flag) {
			this.fileName = fileName;
			this.delvName = delvName;
			this.recCnt = recCnt;
			
			this.raf = new RandomAccessFile(this.fileName, "rw");
		}
		
		if (flag) {
			int idx = this.delvName.lastIndexOf("delv_");
			if (idx < 1)
				throw new Exception("ERROR : wrong file name : [" + this.delvName + "]");
			
			this.strDate = this.delvName.substring(idx +  5, idx + 13);
			this.strTime = this.delvName.substring(idx + 13, idx + 19);
		}
	}
	
	public void readAll() throws Exception {
		
		if (flag) {
			
			this.recSeq = 0;
			this.delvSeq = 0;
			while (true) {
				this.pos = this.raf.getFilePointer();
				this.line = this.raf.readLine();
				if (this.line == null)
					break;
				
				this.recSeq ++;

				this.recLen = this.line.length();
				if (flag) log.debug(String.format("(%02d) (%05d) [%4d:%s]", this.recSeq, this.pos, this.recLen, this.line));
				
				this.byLine = this.line.getBytes();
				
				String strRecFile = FqType.REC_FILE.getString(this.byLine);
				if (flag) log.debug("REC_FILE : [" + strRecFile + "]");
				
				if (REC_FILE_NAME.equals(strRecFile)) {
					this.delvSeq ++;
				}
			}
		}
	}

	public String getRecSeq() throws Exception {
		
		String delvSeq = "00";
		
		if (flag) {
			
			this.recSeq = 0;
			this.delvSeq = 0;
			while (true) {
				this.pos = this.raf.getFilePointer();
				this.line = this.raf.readLine();
				if (this.line == null)
					break;
				
				this.recSeq ++;

				this.recLen = this.line.length();
				if (!flag) log.debug(String.format("(%02d) (%05d) [%4d:%s]", this.recSeq, this.pos, this.recLen, this.line));
				
				this.byLine = this.line.getBytes();
				
				String strRecFile = FqType.REC_FILE.getString(this.byLine);
				if (!flag) log.debug("REC_FILE : [" + strRecFile + "]");
				
				if (REC_FILE_NAME.equals(strRecFile)) {
					this.delvSeq ++;
				}
			}
			
			delvSeq = String.format("%02d", ++ this.delvSeq);
			if (flag) log.debug("REC_SEQ -> " + delvSeq);
		}
		
		return delvSeq;
	}

	public void write() throws Exception {
		
		if (flag) {
			this.raf.seek(this.pos);
			
			this.byLine = FqType.makeBytes();

			if (flag) {
				FqType.FQ_SEQ  .setVal(this.byLine, String.valueOf(++ this.recSeq));
				FqType.FQ_RDR  .setVal(this.byLine, "");
				FqType.FQ_LEN  .setVal(this.byLine, "101");
				FqType.REC_LEN .setVal(this.byLine, "271");
				FqType.REC_CNT .setVal(this.byLine, String.valueOf(this.recCnt));
				FqType.REC_SR  .setVal(this.byLine, "R");
				FqType.REC_ORG .setVal(this.byLine, "POS");
				FqType.REC_FILE.setVal(this.byLine, REC_FILE_NAME);
				FqType.REC_FSIZ.setVal(this.byLine, "11");
				FqType.REC_DATE.setVal(this.byLine, this.strDate);
				FqType.REC_TIME.setVal(this.byLine, this.strTime + "000");
				FqType.REC_SEQ .setVal(this.byLine, String.valueOf(++ this.delvSeq));
				FqType.FILLER  .setVal(this.byLine, "");
			}
			
			this.raf.write(this.byLine);
			this.raf.write((byte) '\n');
		}
	}
	
	public void close() throws Exception {
		
		if (flag) {
			if (raf != null) {
				try {
					raf.close();
				} catch (Exception e) {
					// e.printStackTrace();
				}
			}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			/*
			 * just read all records from the file OASPOS5101
			 */
			
			String fileName = "N:/TEMP/TEST/HANWA/recv/DAT/20160323/OARPOS5101";
			String delvName = "N:/TEMP/TEST/POST_AGENT/receive/delv_20160323142708.txt";
			int recCnt = 3333;
			
			DelvFQ delvFQ = new DelvFQ(fileName, delvName, recCnt);
			
			if (flag) delvFQ.readAll();
			
			if (flag) delvFQ.write();
			
			delvFQ.close();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
