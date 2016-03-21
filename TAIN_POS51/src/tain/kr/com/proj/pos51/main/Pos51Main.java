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

import java.util.ResourceBundle;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : Pos51Main.java
 *   -. Package    : tain.kr.com.proj.pos51.main
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 18. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class Pos51Main {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(Pos51Main.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private String clsName = null;
	
	public Pos51Main() {
		
		if (flag) {
			this.clsName = this.getClass().getName();
		}
	}
	
	public String getClsName() throws Exception {
		
		String ret = null;
		
		if (flag) {
			ret = this.clsName;
		}
		
		return ret;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			String clsName = new Object(){}.getClass().getEnclosingClass().getName();
			
			ResourceBundle rb = ResourceBundle.getBundle(clsName.replace('.', '/'));
			
			if (flag) log.debug("clsName : " + rb.getString("Pos51Main.message"));
		}
		
		if (flag) {
			
			Pos51Main main = new Pos51Main();
			
			if (flag) log.debug("object : " + main.getClsName());
			if (flag) log.debug("object : " + main.getClsName().replace('.', '/'));
		}
	}
	
	private static void test02(String[] args) throws Exception {
		
		if (flag) {

			Thread thread = null;
			
			for (int i=1; ; i++) {
				if (i % 10 == 0)
					i = 0;
				
				/*
				 * HWPOS000001
				 */
				thread = new ThreadHWPOS000001();
				thread.start();
				thread.join();
				
				/*
				 * POSHW000002
				 */
				thread = new ThreadPOSHW000002();
				thread.start();
				thread.join();
				
				/*
				 * POSHW000003
				 */
				thread = new ThreadPOSHW000003();
				thread.start();
				thread.join();
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (!flag) test01(args);
		if (flag) test02(args);
	}
}
