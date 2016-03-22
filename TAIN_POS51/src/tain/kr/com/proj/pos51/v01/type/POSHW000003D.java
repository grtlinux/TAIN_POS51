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
package tain.kr.com.proj.pos51.v01.type;

import java.util.StringTokenizer;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : POSHW000003D.java
 *   -. Package    : tain.kr.com.proj.pos51.type
 *   -. Comment    :
 *   -. Author     : 영업
 *   -. First Date : 2016. 3. 11. {time}
 * </PRE>
 *
 * @author 영업
 *
 */
public enum POSHW000003D {

	/*
	 * 계약등기 > 3.배달결과 > DATA : 271 bytes
	 */
	
	DATA_CLAS         ('C', ' ',     0,   2,   "DATA_CLAS"           ,"데이터구분"                       , "" ),
	OUTSIDUSERID      ('C', ' ',     2,  13,   "OUTSIDUSERID"        ,"외부기관구분코드"                 , "" ),
	REGINO            ('C', ' ',    15,  13,   "REGINO"              ,"등기번호"                         , "" ),
	DELIVYMD          ('C', ' ',    28,   8,   "DELIVYMD"            ,"배달일자"                         , "" ),
	DELIVHHMI         ('C', ' ',    36,   4,   "DELIVHHMI"           ,"배달시분"                         , "" ),
	DELIVRSLTCD       ('C', ' ',    40,   2,   "DELIVRSLTCD"         ,"배달결과코드"                     , "" ),
	NONDELIVREASNCD   ('C', ' ',    42,   2,   "NONDELIVREASNCD"     ,"미배달코드"                       , "" ),
	NONDELIVREASNCDNM ('C', ' ',    44,  90,   "NONDELIVREASNCDNM"   ,"미배달사유명"                     , "" ),
	SUBRECPRSNNM      ('C', ' ',   134,  60,   "SUBRECPRSNNM"        ,"수령인명"                         , "" ),
	RELRECPRSNCD      ('C', ' ',   194,   2,   "RELRECPRSNCD"        ,"수령인관계코드"                   , "" ),
	RELRECPRSNCDNM    ('C', ' ',   196,  60,   "RELRECPRSNCDNM"      ,"수령인관계명"                     , "" ),
	SSN               ('C', ' ',   256,  13,   "SSN"                 ,"생년월일"                         , "" ),
	DELIVRSLTCHGCD    ('C', ' ',   269,   2,   "DELIVRSLTCHGCD"      ,"변경초리구분코드"                 , "" ),
	;
	
	private final char type;
	private final char lead;
	private final int off;
	private final int len;
	private final String name;
	private final String desc;
	private final String defVal; 
	
	public char getType() {
		return this.type;
	}
	
	public char getLead() {
		return this.lead;
	}
	
	public int getOff() {
		return this.off;
	}
	
	public int getLen() {
		return this.len;
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getDesc() {
		return this.desc;
	}
	
	public String getDefVal() {
		return this.defVal;
	}
	
	/**
	 * 
	 * Code Templates > Comments > Constructors
	 *
	 * <PRE>
	 *   -. ClassName  : POSHW000003D
	 *   -. MethodName : POSHW000003D
	 *   -. Comment    :
	 *   -. Author     : taincokr
	 *   -. First Date : 2016. 2. 1. {time}
	 * </PRE>
	 *
	 * @param type
	 * @param lead
	 * @param off
	 * @param len
	 * @param name
	 * @param desc
	 * @param defVal
	 */
	POSHW000003D(char type, char lead, int off, int len, String name, String desc, String defVal) {
		this.type = type;
		this.lead = lead;
		this.off = off;
		this.len = len;
		this.name = name;
		this.desc = desc;
		this.defVal = defVal;
	}
	
	////////////////////////////////////////////////////////////////////
	
	public void fill(byte[] bytes, byte by) throws Exception {
		
		for (int i=0; i < this.len; i++) {
			bytes[this.off + i] = by;
		}
	}
	
	public void setVal(byte[] bytes) throws Exception  {
		// clear the exist string
		fill(bytes, (byte)' ');
	}
	
	public void setVal(byte[] bytes, byte[] byVal) throws Exception {
		
		if (byVal == null) {
			// clear the exist string
			fill(bytes, (byte)' ');
			return;
		}
		
		int byLen = byVal.length;
		
		if (this.type == 'C') {
			// left arrange
			for (int i=0, j=0; i < this.len; i++, j++) {
				if (j < byLen) {
					bytes[this.off + i] = byVal[j];
				} else {
					bytes[this.off + i] = (byte) this.lead;
				}
			}
		} else if (this.type == 'N') {
			// right arrange
			for (int i=0, j=0; i < this.len; i++, j++) {
				if (j < byLen) {
					bytes[this.off + this.len - 1 - i] = byVal[byLen - 1 - j];
				} else {
					bytes[this.off + this.len - 1 - i] = (byte) this.lead;
				}
			}
		} else {
			// TODO 2016.03.08 : ERROR
		}
	}
	
	public void setVal(byte[] bytes, String strVal) throws Exception {
		if (strVal == null) {
			// clear the exist string
			fill(bytes, (byte)' ');
			return;
		}
		
		setVal(bytes, strVal.getBytes("EUC-KR"));
	}
	
	public String getString(byte[] bytes) throws Exception {
		return new String(bytes, this.off, this.len);
	}
	
	public byte[] getBytes(byte[] bytes) throws Exception {
		byte[] ret = new byte[this.len];
		
		for (int i=0; i < this.len; i++) {
			ret[i] = bytes[this.off + i];
		}
		
		return ret;
	}

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	private static boolean flag = true;
	
	private static int cntFld = -1;
	private static int lenTotal = -1;
	
	private static int setLenTotal() throws Exception {
		
		if (lenTotal < 0) {
			int cnt = 0;
			int off = 0;
			
			for (POSHW000003D fld : POSHW000003D.values()) {
				off += fld.getLen();
				cnt ++;
			}
			
			lenTotal = off;
			cntFld = cnt;
		}
		
		return lenTotal;
	}
	
	public static int getCntFld() throws Exception {
		setLenTotal();
		return cntFld;
	}
	
	public static int getLength() throws Exception {
		setLenTotal();
		return lenTotal;
	}
	
	public static byte[] makeBytes() throws Exception {
		
		setLenTotal();
		
		byte[] bytes = new byte[lenTotal];
		
		if (flag) {
			for (POSHW000003D fld : POSHW000003D.values()) {
				fld.setVal(bytes, fld.getDefVal());
			}
		}
		
		if (flag) {
			POSHW000003D.DATA_CLAS         .setVal(bytes, "DT");
			POSHW000003D.OUTSIDUSERID      .setVal(bytes, "");
			POSHW000003D.REGINO            .setVal(bytes, "");
			POSHW000003D.DELIVYMD          .setVal(bytes, "");
			POSHW000003D.DELIVHHMI         .setVal(bytes, "");
			POSHW000003D.DELIVRSLTCD       .setVal(bytes, "");
			POSHW000003D.NONDELIVREASNCD   .setVal(bytes, "");
			POSHW000003D.NONDELIVREASNCDNM .setVal(bytes, "");
			POSHW000003D.SUBRECPRSNNM      .setVal(bytes, "");
			POSHW000003D.RELRECPRSNCD      .setVal(bytes, "");
			POSHW000003D.RELRECPRSNCDNM    .setVal(bytes, "");
			POSHW000003D.SSN               .setVal(bytes, "");
			POSHW000003D.DELIVRSLTCHGCD    .setVal(bytes, "");
		}
		
		return bytes;
	}
	
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////

	public static String compress(byte[] bytes) throws Exception {
		
		StringBuffer sb = new StringBuffer();
		
		for (POSHW000003D fld : POSHW000003D.values()) {
			
			sb.append(fld.getString(bytes).trim()).append("|");
		}
		
		if (flag) sb.deleteCharAt(sb.length() - 1);

		return sb.toString();
	}
	
	public static String decompress(byte[] bytes) throws Exception {
		
		byte[] ret = null;
		
		if (!flag) {
			/*
			 * TODO 20160308 : for test
			 */
			StringTokenizer st = new StringTokenizer(new String(bytes), "|", false);
			int count = st.countTokens();
			
			for (int i=0; i < count && st.hasMoreTokens(); i++) {
				String str = st.nextToken();
				
				if (flag) log.debug("> [" + str + "]");
			}
		}
		
		if (flag) {
			/*
			 * 
			 */
			ret = POSHW000003D.makeBytes();
			
			String[] items = new String(bytes).split("\\|", POSHW000003D.getCntFld());   // TODO 2016.03.14 : have to fix the field count... ^^
			int i = 0;
			
			for (POSHW000003D fld : POSHW000003D.values()) {
				
				if (!flag) log.debug("> [" + items[i] + "]");
				if (flag) log.debug(String.format("> [%-20s] [%s]", fld.name, items[i]));

				fld.setVal(ret, items[i]);
				++ i;
			}
		}
		
		return new String(ret);
	}
	
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	private static final Logger log = Logger.getLogger(POSHW000003D.class);
	
	public static void print() throws Exception {
		
		if (flag) {
			int len = 0;
			int off = 0;
			for (POSHW000003D fld : POSHW000003D.values()) {
				len = fld.getLen();
				
				if (flag) log.debug(String.format("[%s] [%3d:%3d] [%3d:%3d] [%-10s] [%s] [%s]"
						, fld.getType(), off, fld.getOff(), len, fld.getLen(), fld.getName(), fld.getDesc(), fld.getDefVal()));
				
				off += fld.getLen();
			}
			
			if (flag) log.debug("Total Length = " + off);
		}
	}
	
	public static void print(byte[] bytes) throws Exception {
		
		if (flag) {
			int len = 0;
			int off = 0;
			for (POSHW000003D fld : POSHW000003D.values()) {
				len = fld.getLen();
				
				if (flag) log.debug(String.format("[%s] [%3d:%3d] [%3d:%3d] [%-10s] [%s]"
						, fld.getType(), off, fld.getOff(), len, fld.getLen(), fld.getName(), fld.getString(bytes)));
				
				off += fld.getLen();
			}
			
			if (flag) log.debug("[" + new String(bytes) + "]");
			if (flag) log.debug("Total Length = " + off);
		}
	}
	
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			
			if (flag) log.debug(String.format("[FLD_CNT:%d] [REC_LEN:%d]", POSHW000003D.getCntFld(), POSHW000003D.getLength()));
			
			byte[] bytes = POSHW000003D.makeBytes();
			
			POSHW000003D.DATA_CLAS         .setVal(bytes, "DT");
			POSHW000003D.OUTSIDUSERID      .setVal(bytes, "");
			POSHW000003D.REGINO            .setVal(bytes, "");
			POSHW000003D.DELIVYMD          .setVal(bytes, "");
			POSHW000003D.DELIVHHMI         .setVal(bytes, "");
			POSHW000003D.DELIVRSLTCD       .setVal(bytes, "");
			POSHW000003D.NONDELIVREASNCD   .setVal(bytes, "");
			POSHW000003D.NONDELIVREASNCDNM .setVal(bytes, "");
			POSHW000003D.SUBRECPRSNNM      .setVal(bytes, "");
			POSHW000003D.RELRECPRSNCD      .setVal(bytes, "");
			POSHW000003D.RELRECPRSNCDNM    .setVal(bytes, "");
			POSHW000003D.SSN               .setVal(bytes, "");
			POSHW000003D.DELIVRSLTCHGCD    .setVal(bytes, "");
			
			POSHW000003D.print();
			POSHW000003D.print(bytes);
			
			String strCompress = POSHW000003D.compress(bytes);
			if (flag) log.debug("> COMPRESS [" + strCompress + "]");
			
			String strDecompress = POSHW000003D.decompress(strCompress.getBytes("EUC-KR"));
			if (flag) log.debug("> DECOMPRESS [" + strDecompress + "]");
			
			if (strDecompress.equals(new String(bytes))) {
				log.debug(">>>>> EQUALS");
			} else {
				log.debug(">>>>> MISMATCH");
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());

		if (flag) test01(args);
	}
}
