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

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.ResourceBundle;

import org.apache.log4j.Logger;

import tain.kr.com.proj.pos51.type.HWPOS000001D;
import tain.kr.com.proj.pos51.type.HWPOS000001H;
import tain.kr.com.proj.pos51.type.HWPOS000001T;

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
	private String inFileName = null;
	
	private String outCharSet = null;
	private String outPath = null;
	private String outName = null;
	private String outFileName = null;
	
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
			this.inFileName = this.inPath + File.separator + this.inName;

			this.outCharSet = rb.getString("tain.hwpos000001.out.file.charset");
			this.outPath = rb.getString("tain.hwpos000001.out.file.path");
			this.outName = rb.getString("tain.hwpos000001.out.file.name").replaceAll("YYYYMMDDHHMMSS", this.yyyymmddhhmmss);
			this.outFileName = this.outPath + File.separator + this.outName;
			
			if (flag) {
				/*
				 * print properties
				 */
				log.debug("inCharSet   : " + this.inCharSet);
				log.debug("inPath      : " + this.inPath);
				log.debug("inName      : " + this.inName);
				log.debug("inFileName  : " + this.inFileName);

				log.debug("outCharSet  : " + this.outCharSet);
				log.debug("outPath     : " + this.outPath);
				log.debug("outName     : " + this.outName);
				log.debug("outFileName : " + this.outFileName);
			}
		}
	}
	
	public void run() {
		
		if (flag) {
			System.setProperty("line.separator", "\n");
		}

		if (flag) {

			try {
				// in file
				File inFile = new File(this.inFileName);
				FileInputStream inFileStream = new FileInputStream(inFile);
				BufferedReader inReader = new BufferedReader(new InputStreamReader(inFileStream, this.inCharSet));
				
				// out file
				File outFile = new File(this.outFileName);
				FileOutputStream outFileStream = new FileOutputStream(outFile);
				OutputStreamWriter outWriter = new OutputStreamWriter(outFileStream, this.outCharSet);
				PrintWriter writer = new PrintWriter(outWriter);
				
				String line = null;
				
				while ((line = inReader.readLine()) != null) {
					if (flag) log.debug("[" + line + "]");
					
					byte[] byLine = line.getBytes();
					String dataClas = HWPOS000001H.DATA_CLAS.getString(byLine);
					
					switch (dataClas) {
					case "HD":
						if (flag) {
							if (flag) log.debug("line   HWPOS000001H [" + line + "]");
							line = HWPOS000001H.compress(byLine);
							if (flag) log.debug("comp   HWPOS000001H [" + line + "]");
						}
						break;
					case "DT":
						if (flag) {
							if (flag) log.debug("line   HWPOS000001D [" + line + "]");
							line = HWPOS000001D.compress(byLine);
							if (flag) log.debug("comp   HWPOS000001D [" + line + "]");
						}
						break;
					case "TR":
						if (flag) {
							if (flag) log.debug("line   HWPOS000001T [" + line + "]");
							line = HWPOS000001T.compress(byLine);
							if (flag) log.debug("comp   HWPOS000001T [" + line + "]");
						}
						break;
					default:
						break;
					}

					writer.println(line);
				}
				
				inReader.close();
				writer.close();

			} catch (Exception e) {
				e.printStackTrace();
			} finally {
				
			}
		}
		
		if (flag) {
			try { Thread.sleep(1000); } catch (InterruptedException e) {}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

}
