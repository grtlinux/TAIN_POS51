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
package tain.kr.com.proj.pos51.main;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.ResourceBundle;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : ThreadHWPOS000001.java
 *   -. Package    : tain.kr.com.proj.pos51.main
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 21. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class ThreadHWPOS000001 extends Thread {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(ThreadHWPOS000001.class);

	///////////////////////////////////////////////////////////////////////////////////////////////

	private String yyyymmdd = null;
	private String yyyymmddhhmmss = null;
	
	private String clsName = null;

	private String inCharSet = null;
	private String inPath = null;
	private String inName = null;
	
	private String outCharSet = null;
	private String outPath = null;
	private String outName = null;
	
	public ThreadHWPOS000001() {
		
		if (flag) log.debug(">>>>> " + this.getClass().getName());
		
		if (flag) {
			
			this.yyyymmdd = new SimpleDateFormat("yyyyMMdd").format(new Date());
			this.yyyymmddhhmmss = new SimpleDateFormat("yyyyMMddHHmmss").format(new Date());
		}
		
		if (flag) {
			/*
			 * read properties
			 */
			this.clsName = this.getClass().getName();
			
			ResourceBundle rb = ResourceBundle.getBundle(clsName.replace('.', '/'));
			
			this.inCharSet = rb.getString("tain.hwpos000001.in.file.charset");
			this.inPath = rb.getString("tain.hwpos000001.in.file.path").replaceAll("YYYYMMDD", this.yyyymmdd);
			this.inName = rb.getString("tain.hwpos000001.in.file.name").replaceAll("YYYYMMDD", this.yyyymmdd);

			this.outCharSet = rb.getString("tain.hwpos000001.out.file.charset");
			this.outPath = rb.getString("tain.hwpos000001.out.file.path");
			this.outName = rb.getString("tain.hwpos000001.out.file.name").replaceAll("YYYYMMDDHHMMSS", this.yyyymmddhhmmss);
			
			if (flag) {
				/*
				 * print properties
				 */
				log.debug("inCharSet  : " + this.inCharSet);
				log.debug("inPath     : " + this.inPath);
				log.debug("inName     : " + this.inName);

				log.debug("outCharSet : " + this.outCharSet);
				log.debug("outPath    : " + this.outPath);
				log.debug("outName    : " + this.outName);
			}
		}
	}
	
	public void run() {
		
		if (flag) {
			
		}
		
		if (flag) {
			try { Thread.sleep(1000); } catch (InterruptedException e) {}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

}
