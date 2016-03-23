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
 *   -. FileName   : SendFQ.java
 *   -. Package    : tain.kr.com.proj.pos51.v02.util
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 22. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class SendFQ {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(SendFQ.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private static final String FQ_READER = "HWPOS00000";
	
	private String fileName = null;
	private RandomAccessFile raf = null;
	private String line = null;
	private byte[] byLine = null;
	private long pos = -1;
	private int recLen = -1;
	
	private String strSendSeq = null;
	private String strDateTime = null;
	private boolean flagExecute = false;
	
	public SendFQ(String fileName) throws Exception {
		
		if (flag) {
			this.fileName = fileName;
			
			this.raf = new RandomAccessFile(this.fileName, "rw");
		}
	}
	
	private void readAll() throws Exception {
		
		if (flag) {
			
			while (true) {
				this.pos = this.raf.getFilePointer();
				this.line = this.raf.readLine();
				if (this.line == null)
					break;
				
				this.recLen = this.line.length();
				if (flag) log.debug(String.format("READ  (POS:%05d) [%4d:%s]", this.pos, this.recLen, this.line));
				
				this.byLine = this.line.getBytes();
				
				String strFqRdr = FqType.FQ_RDR.getString(this.byLine);
				if (flag) log.debug("FQ_RDR : [" + strFqRdr + "]");
			}
		}
	}
	
	public boolean read() throws Exception {
		
		this.flagExecute = false;
		
		if (flag) {
			
			while (true) {
				this.pos = this.raf.getFilePointer();
				this.line = this.raf.readLine();
				if (this.line == null)
					break;
				
				this.recLen = this.line.length();
				if (flag) log.debug(String.format("READ  (POS:%05d) [%4d:%s]", this.pos, this.recLen, this.line));
				
				this.byLine = this.line.getBytes();
				
				String strFqRdr = FqType.FQ_RDR.getString(this.byLine);
				if (flag) log.debug("FQ_RDR : [" + strFqRdr + "]");
				if ("          ".equals(strFqRdr)) {
					
					this.strSendSeq = FqType.REC_SEQ.getString(this.byLine);
					this.strDateTime = FqType.REC_DATE.getString(this.byLine) + FqType.REC_TIME.getString(this.byLine);
					this.strDateTime = this.strDateTime.substring(0, 14);
					
					this.flagExecute = true;
					return this.flagExecute;
				}
			}
		}
		
		return this.flagExecute;
	}
	
	public String getSendSeq() throws Exception {
		
		return this.strSendSeq;
	}
	
	public String getDateTime() throws Exception {
		
		return this.strDateTime;
	}
	
	public boolean isFlag() throws Exception {
		
		return this.flagExecute;
	}
	
	public void write() throws Exception {
		
		if (flag) {
			this.raf.seek(this.pos);
			
			FqType.FQ_RDR.setVal(byLine, FQ_READER);
			
			this.raf.write(this.byLine);
			
			if (flag) log.debug(String.format("WRITE (POS:%05d) [%4d:%s]", this.pos, this.recLen, new String(this.byLine)));
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
		
		if (!flag) {
			/*
			 * just read all records from the file OASPOS5101
			 */
			
			String fileName = "N:/TEMP/TEST/HANWA/send/DAT/20160323/OASPOS5101";
			
			SendFQ sendFQ = new SendFQ(fileName);
			
			sendFQ.readAll();
			
			sendFQ.close();
		}
		
		if (flag) {
			/*
			 * if FQ_RDR is spaces after reading a line, write FQ_RDR into the line of the file OASPOS51 
			 */
			
			String fileName = "N:/TEMP/TEST/HANWA/send/DAT/20160323/OASPOS5101";
			
			SendFQ sendFQ = new SendFQ(fileName);
			
			if (sendFQ.read()) {
				sendFQ.write();
			}
			
			sendFQ.close();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
